using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO.Ports;

namespace TpMonitor
{

    public delegate void DataReadyHandler(object sender);

    class SerialData
    {

        public event DataReadyHandler DataReady;

        SerialPort commPort = new SerialPort("tempName", 9600, Parity.None, 8, StopBits.One);
        public byte[] txBuffer = new byte[10];
        public byte[] rxBuffer = new byte[10];
        byte rxIndex = 0;
        bool startOfFrameDetected = false;

        public SerialData()
        {
            commPort.DataReceived += commPort_DataReceived;
        }

        void commPort_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            while (commPort.BytesToRead > 0)
            {
                rxBuffer[rxIndex] = (byte)commPort.ReadByte();
                if ((rxIndex == 0) && (rxBuffer[0] == 0x7F) && (startOfFrameDetected == false))
                {
                    startOfFrameDetected = true;
                    rxIndex++;
                }
                else if ((rxIndex >= 9) && (startOfFrameDetected == true))
                {
                    rxIndex = 0;
                    if (DataReady != null)
                        DataReady(this);

                }
                else
                {
                    rxIndex++;
                }
            }
        }

        public void txData(byte txLength)
        {
            commPort.Write(txBuffer, 0, txLength);
        }

        public bool openPort(string portName)
        {
            commPort.PortName = portName;

            try
            {
                commPort.Open();
                return true;
            }
            catch
            {
                return false;
            }




        }

    }
}
