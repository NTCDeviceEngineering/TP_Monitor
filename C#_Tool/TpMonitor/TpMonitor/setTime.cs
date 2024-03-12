using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TpMonitor
{
    public partial class setTime : Form
    {
        setTimeVars setTimeObj = new setTimeVars();
        
        public setTime()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int year = (int)Convert.ToUInt32(yearCb.Text);
            int month = (int)Convert.ToUInt32(monthCb.Text);
            int day = (int)Convert.ToUInt32(dayCb.Text);
            int hour = (int)Convert.ToUInt32(hourCb.Text);
            int minutes = (int)Convert.ToUInt32(minCb.Text);

            setTimeObj.setTimeFun(year, month, day, hour, minutes);
   

            this.Close();
        }
    }
}
