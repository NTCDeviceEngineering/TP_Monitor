namespace TpMonitor
{
    partial class setTime
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label3 = new System.Windows.Forms.Label();
            this.dayCb = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.monthCb = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.yearCb = new System.Windows.Forms.ComboBox();
            this.button1 = new System.Windows.Forms.Button();
            this.hourCb = new System.Windows.Forms.ComboBox();
            this.label4 = new System.Windows.Forms.Label();
            this.minLbl = new System.Windows.Forms.Label();
            this.minCb = new System.Windows.Forms.ComboBox();
            this.SuspendLayout();
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.ForeColor = System.Drawing.Color.Yellow;
            this.label3.Location = new System.Drawing.Point(290, 18);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(33, 17);
            this.label3.TabIndex = 13;
            this.label3.Text = "Day";
            // 
            // dayCb
            // 
            this.dayCb.AutoCompleteCustomSource.AddRange(new string[] {
            "2013",
            "2014",
            "2015"});
            this.dayCb.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.dayCb.FormattingEnabled = true;
            this.dayCb.Items.AddRange(new object[] {
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8",
            "9",
            "10",
            "11",
            "12",
            "13",
            "14",
            "15",
            "16",
            "17",
            "18",
            "19",
            "20",
            "21",
            "22",
            "23",
            "24",
            "25",
            "26",
            "27",
            "28",
            "29",
            "30",
            "31"});
            this.dayCb.Location = new System.Drawing.Point(257, 47);
            this.dayCb.Name = "dayCb";
            this.dayCb.Size = new System.Drawing.Size(105, 28);
            this.dayCb.TabIndex = 12;
            this.dayCb.Text = "1";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.ForeColor = System.Drawing.Color.Yellow;
            this.label2.Location = new System.Drawing.Point(168, 18);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(47, 17);
            this.label2.TabIndex = 11;
            this.label2.Text = "Month";
            // 
            // monthCb
            // 
            this.monthCb.AutoCompleteCustomSource.AddRange(new string[] {
            "2013",
            "2014",
            "2015"});
            this.monthCb.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.monthCb.FormattingEnabled = true;
            this.monthCb.Items.AddRange(new object[] {
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8",
            "9",
            "10",
            "11",
            "12"});
            this.monthCb.Location = new System.Drawing.Point(135, 47);
            this.monthCb.Name = "monthCb";
            this.monthCb.Size = new System.Drawing.Size(105, 28);
            this.monthCb.TabIndex = 10;
            this.monthCb.Text = "1";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.ForeColor = System.Drawing.Color.Yellow;
            this.label1.Location = new System.Drawing.Point(45, 18);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(38, 17);
            this.label1.TabIndex = 9;
            this.label1.Text = "Year";
            // 
            // yearCb
            // 
            this.yearCb.AutoCompleteCustomSource.AddRange(new string[] {
            "2013",
            "2014",
            "2015"});
            this.yearCb.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.yearCb.FormattingEnabled = true;
            this.yearCb.Items.AddRange(new object[] {
            "2013",
            "2014",
            "2015"});
            this.yearCb.Location = new System.Drawing.Point(12, 47);
            this.yearCb.Name = "yearCb";
            this.yearCb.Size = new System.Drawing.Size(105, 28);
            this.yearCb.TabIndex = 8;
            this.yearCb.Text = "2014";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(247, 108);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(149, 63);
            this.button1.TabIndex = 7;
            this.button1.Text = "Set Time";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // hourCb
            // 
            this.hourCb.AutoCompleteCustomSource.AddRange(new string[] {
            "2013",
            "2014",
            "2015"});
            this.hourCb.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.hourCb.FormattingEnabled = true;
            this.hourCb.Items.AddRange(new object[] {
            "0",
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8",
            "9",
            "10",
            "11",
            "12",
            "13",
            "14",
            "15",
            "16",
            "17",
            "18",
            "19",
            "20",
            "21",
            "22",
            "23"});
            this.hourCb.Location = new System.Drawing.Point(380, 47);
            this.hourCb.Name = "hourCb";
            this.hourCb.Size = new System.Drawing.Size(105, 28);
            this.hourCb.TabIndex = 14;
            this.hourCb.Text = "1";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.ForeColor = System.Drawing.Color.Yellow;
            this.label4.Location = new System.Drawing.Point(416, 18);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(39, 17);
            this.label4.TabIndex = 15;
            this.label4.Text = "Hour";
            // 
            // minLbl
            // 
            this.minLbl.AutoSize = true;
            this.minLbl.ForeColor = System.Drawing.Color.Yellow;
            this.minLbl.Location = new System.Drawing.Point(544, 18);
            this.minLbl.Name = "minLbl";
            this.minLbl.Size = new System.Drawing.Size(57, 17);
            this.minLbl.TabIndex = 17;
            this.minLbl.Text = "Minutes";
            // 
            // minCb
            // 
            this.minCb.AutoCompleteCustomSource.AddRange(new string[] {
            "2013",
            "2014",
            "2015"});
            this.minCb.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.minCb.FormattingEnabled = true;
            this.minCb.Items.AddRange(new object[] {
            "0",
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8",
            "9",
            "10",
            "11",
            "12",
            "13",
            "14",
            "15",
            "16",
            "17",
            "18",
            "19",
            "20",
            "21",
            "22",
            "23",
            "24",
            "25",
            "26",
            "27",
            "28",
            "29",
            "30",
            "31",
            "32",
            "33",
            "34",
            "35",
            "36",
            "37",
            "38",
            "39",
            "40",
            "41",
            "42",
            "43",
            "44",
            "45",
            "46",
            "47",
            "48",
            "49",
            "50",
            "51",
            "52",
            "53",
            "54",
            "55",
            "56",
            "57",
            "58",
            "59"});
            this.minCb.Location = new System.Drawing.Point(508, 47);
            this.minCb.Name = "minCb";
            this.minCb.Size = new System.Drawing.Size(105, 28);
            this.minCb.TabIndex = 16;
            this.minCb.Text = "1";
            // 
            // setTime
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Black;
            this.ClientSize = new System.Drawing.Size(659, 205);
            this.Controls.Add(this.minLbl);
            this.Controls.Add(this.minCb);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.hourCb);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.dayCb);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.monthCb);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.yearCb);
            this.Controls.Add(this.button1);
            this.Name = "setTime";
            this.Text = "setTime";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ComboBox dayCb;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox monthCb;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox yearCb;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.ComboBox hourCb;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label minLbl;
        private System.Windows.Forms.ComboBox minCb;
    }
}