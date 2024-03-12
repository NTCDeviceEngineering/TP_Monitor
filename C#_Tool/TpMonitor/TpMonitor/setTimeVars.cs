using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TpMonitor
{
    class setTimeVars
    {
        public static DateTime dtInstalled = new DateTime();

        public void setTimeFun(int Year, int Month, int Day, int Hour, int Minutes)
        {
            //DateTime tempTime = new DateTime(Year, Month, Day, Hour, 0, 0);
            DateTime tempTime = new DateTime(Year, Month, Day, Hour, Minutes, 0);

            dtInstalled = tempTime;
        }

        public DateTime getTime()
        {
            return dtInstalled;
        }
    }
}
