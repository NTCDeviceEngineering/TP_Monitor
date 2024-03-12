using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using System.IO;

namespace TpMonitor
{
    
    public partial class Form1 : Form
    {
        delegate void updateFormDelegate();
        delegate void updateFormNumRecDelegate();
        
        setTimeVars dtObj2 = new setTimeVars();
        setTime newform = new setTime();
        SerialData sData = new SerialData();
        Timer genTimer = new Timer();

        UInt16 numOfRecords = 0;
        bool numOfRecFlag = true;


        UInt16 rxIndex = 0;
        UInt32[] timeStamp = new UInt32[18000];
        byte[]   msgType   = new byte[18000];
        UInt16[] message   = new UInt16[18000];
        byte[]   lastByte  = new byte[18000];
        
        public Form1()
        {
            InitializeComponent();
            newform.FormClosing += newform_FormClosing;
            sData.DataReady += sData_DataReady;
            genTimer.Tick += genTimer_Tick;
        }

        void genTimer_Tick(object sender, EventArgs e)
        {
            genTimer.Enabled = false;
            this.Enabled = true;
        }

        void updateFormNumRec()
        {
            textBox1.Text = numOfRecords.ToString();
            numRecBar.Maximum = numOfRecords;
        }

        void updateFormData()
        {
            numRecBar.Value = rxIndex;
        }

        void sData_DataReady(object sender)
        {
           
            if (numOfRecFlag == true)
            {
                numOfRecFlag = false;
                rxIndex = 0;
                numOfRecords = BitConverter.ToUInt16(sData.rxBuffer, 2);
                Invoke(new updateFormNumRecDelegate(updateFormNumRec));
            }
            else
            {
                timeStamp[rxIndex] = BitConverter.ToUInt32(sData.rxBuffer, 1);
                msgType[rxIndex]   = sData.rxBuffer[5];
                message[rxIndex]   = BitConverter.ToUInt16(sData.rxBuffer, 6);
                lastByte[rxIndex++]  = sData.rxBuffer[8];

                Invoke(new updateFormDelegate(updateFormData));
            }
           
        }

        void resetGetData()
        {
            numOfRecFlag = true;
            getDataBtn.Enabled = true;
            numRecBar.Value = 0;
            textBox1.Text = "";
        }

        void newform_FormClosing(object sender, FormClosingEventArgs e)
        {
            dtTb.Text = (dtObj2.getTime()).ToString();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            genTimer.Enabled = false; 
        }

        private void button3_Click(object sender, EventArgs e)
        {
            newform.ShowDialog();
        }


        private void getDataBtn_Click(object sender, EventArgs e)
        {
            sData.txBuffer[0] = 0x7F;
            sData.txBuffer[1] = 0x01; // get data
            sData.txData(2);
            getDataBtn.Enabled = false;
        }

        private void comboBox1_MouseDown(object sender, MouseEventArgs e)
        {
            comboBox1.Items.Clear();

            foreach (string commPortName in SerialPort.GetPortNames())
            {
                comboBox1.Items.Add(commPortName);
            }
        }

        private void comboBox1_TextChanged(object sender, EventArgs e)
        {
            if (sData.openPort(comboBox1.Text) == true)
            {
                connStatusLbl.ForeColor = Color.Lime;
                connStatusLbl.Text = "Connected";
                button1.BackColor = Color.Lime;
                comboBox1.Enabled = false;
            }
            else
            {
                connStatusLbl.Text = "Not Connected";
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            saveCSV.Filter = "CSV Files (.csv)|*.csv|All Files (*.*)|*.*";
            saveCSV.FilterIndex = 1;

            resetGetData();

            if (saveCSV.ShowDialog() == DialogResult.OK)
            {
                writeCsvFile();
            }
        }
        private void writeCsvFile()
        {
            string rowString   = "";
            float lengthInInch = 0;
            byte tempMsgType   = 0;
            float adReading = 0;
            float battVoltage = 0;

            DateTime tempTime = new DateTime();

            StreamWriter objWriter = new StreamWriter(saveCSV.FileName, true);
            rowString = "";
            rowString = "Message Type,   Date / Time,  Length (in),  Direction,    Paper Roll,  IR Sensor,  Voltage";

            objWriter.WriteLine(rowString);

            rowString = "";

            for (uint i = 0; i < numOfRecords; i++)
            {
                tempTime = dtObj2.getTime();
                tempTime = tempTime.AddSeconds(timeStamp[i]);
                rowString = tempTime.ToString();
                rowString += ", ";
                tempMsgType = msgType[i];

                switch(tempMsgType)
                {
                    case 0xF0:
                      
                        rowString = "TP dispense," + tempTime.ToString() + ", ";
                        lengthInInch = (float)Math.Round((float)(message[i] * 0.035), 2);
                        rowString += (lengthInInch.ToString() + ", ");
                        if(lastByte[i]==0)
                        {
                            rowString += ("CCW" + ", ");
                        }
                        else if (lastByte[i] == 1)
                        {
                            rowString += ("CW" + ", ");
                        }
                        else
                        {
                            rowString += ("Direction error" + ", ");
                        }
                       
                        rowString += ("Roll A, N/A, N/A");
                        
                        objWriter.WriteLine(rowString);
                        rowString = "";
                        
                        break;

                    case 0xF1:
                        
                        rowString = "TP dispense," + tempTime.ToString() + ", ";
                        lengthInInch = (float)Math.Round((float)(message[i] * 0.035), 2);
                        rowString += (lengthInInch.ToString() + ", ");
                        if(lastByte[i]==0)
                        {
                            rowString += ("CCW" + ", ");
                        }
                        else if (lastByte[i] == 1)
                        {
                            rowString += ("CW" + ", ");
                        }
                        else
                        {
                            rowString += ("Direction error" + ", ");
                        }
                       
                        rowString += ("Roll B, N/A, N/A");
                        
                        objWriter.WriteLine(rowString);
                        rowString = "";

                        break;

                    case 0xF2:

                        rowString = "IR Sensor," + tempTime.ToString() + ", N/A, N/A, N/A, ";
                        if (message[i]== 0xF000)
                        {
                            rowString += ("IR Sensor A, N/A");
                        }
                        else if (message[i] == 0xF001)
                        {
                            rowString += ("IR Sensor B, N/A");
                        }


                        objWriter.WriteLine(rowString);
                        rowString = "";

                        break;

                    case 0xF4:

                        rowString = "low Batt. Level," + tempTime.ToString() + ", N/A, N/A, N/A, N/A, ";

                        adReading = message[i];
                        battVoltage = (float)Math.Round(((adReading / 4096) * 6.6), 2);
                        rowString += battVoltage.ToString();
                        objWriter.WriteLine(rowString);
                        rowString = "";
                        
                        break;

                    case 0xF8:

                        rowString = "Power-up," + tempTime.ToString() + ", N/A, N/A, N/A, N/A, N/A";
                        objWriter.WriteLine(rowString);
                        rowString = "";
                        
                        break;

                    default:

                        break;
                }

            }

            objWriter.Close();

            button4.Enabled = true;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            genTimer.Interval = 6000;
            genTimer.Enabled = true;
            this.Enabled = false;
            sData.txBuffer[0] = 0x7F;
            sData.txBuffer[1] = 0x10; // erase data
            sData.txData(2);
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }


    }
}
