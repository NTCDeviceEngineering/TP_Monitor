namespace TpMonitor
{
    partial class Form1
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
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.button1 = new System.Windows.Forms.Button();
            this.connStatusLbl = new System.Windows.Forms.Label();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.getDataBtn = new System.Windows.Forms.Button();
            this.dtTb = new System.Windows.Forms.TextBox();
            this.button3 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.label11 = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.numRecLbl = new System.Windows.Forms.Label();
            this.numRecBar = new System.Windows.Forms.ProgressBar();
            this.rtEnabled = new System.Windows.Forms.RadioButton();
            this.rtDisabled = new System.Windows.Forms.RadioButton();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.button4 = new System.Windows.Forms.Button();
            this.saveCSV = new System.Windows.Forms.SaveFileDialog();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.button1);
            this.groupBox1.Controls.Add(this.connStatusLbl);
            this.groupBox1.Controls.Add(this.comboBox1);
            this.groupBox1.ForeColor = System.Drawing.Color.Yellow;
            this.groupBox1.Location = new System.Drawing.Point(307, 204);
            this.groupBox1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Padding = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.groupBox1.Size = new System.Drawing.Size(282, 41);
            this.groupBox1.TabIndex = 1;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Select Comm Port";
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.Red;
            this.button1.Enabled = false;
            this.button1.Location = new System.Drawing.Point(128, 19);
            this.button1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(22, 16);
            this.button1.TabIndex = 2;
            this.button1.UseVisualStyleBackColor = false;
            // 
            // connStatusLbl
            // 
            this.connStatusLbl.AutoSize = true;
            this.connStatusLbl.ForeColor = System.Drawing.Color.Red;
            this.connStatusLbl.Location = new System.Drawing.Point(20, 17);
            this.connStatusLbl.Name = "connStatusLbl";
            this.connStatusLbl.Size = new System.Drawing.Size(102, 17);
            this.connStatusLbl.TabIndex = 1;
            this.connStatusLbl.Text = "Not Connected";
            // 
            // comboBox1
            // 
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Location = new System.Drawing.Point(156, 14);
            this.comboBox1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(81, 24);
            this.comboBox1.TabIndex = 0;
            this.comboBox1.SelectedIndexChanged += new System.EventHandler(this.comboBox1_SelectedIndexChanged);
            this.comboBox1.TextChanged += new System.EventHandler(this.comboBox1_TextChanged);
            this.comboBox1.MouseDown += new System.Windows.Forms.MouseEventHandler(this.comboBox1_MouseDown);
            // 
            // getDataBtn
            // 
            this.getDataBtn.BackColor = System.Drawing.Color.Black;
            this.getDataBtn.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.getDataBtn.ForeColor = System.Drawing.Color.Yellow;
            this.getDataBtn.Location = new System.Drawing.Point(12, 11);
            this.getDataBtn.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.getDataBtn.Name = "getDataBtn";
            this.getDataBtn.Size = new System.Drawing.Size(577, 55);
            this.getDataBtn.TabIndex = 2;
            this.getDataBtn.Text = "Get the data from the unit";
            this.getDataBtn.UseVisualStyleBackColor = false;
            this.getDataBtn.Click += new System.EventHandler(this.getDataBtn_Click);
            // 
            // dtTb
            // 
            this.dtTb.BackColor = System.Drawing.Color.Black;
            this.dtTb.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.dtTb.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.dtTb.ForeColor = System.Drawing.Color.Lime;
            this.dtTb.Location = new System.Drawing.Point(315, 169);
            this.dtTb.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.dtTb.Name = "dtTb";
            this.dtTb.ReadOnly = true;
            this.dtTb.Size = new System.Drawing.Size(255, 20);
            this.dtTb.TabIndex = 31;
            this.dtTb.Text = "not set";
            this.dtTb.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // button3
            // 
            this.button3.BackColor = System.Drawing.Color.Black;
            this.button3.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button3.ForeColor = System.Drawing.Color.Aqua;
            this.button3.Location = new System.Drawing.Point(305, 128);
            this.button3.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(284, 37);
            this.button3.TabIndex = 30;
            this.button3.Text = "Set the time when installed";
            this.button3.UseVisualStyleBackColor = false;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // button2
            // 
            this.button2.BackColor = System.Drawing.Color.Black;
            this.button2.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button2.ForeColor = System.Drawing.Color.Yellow;
            this.button2.Location = new System.Drawing.Point(12, 128);
            this.button2.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(134, 114);
            this.button2.TabIndex = 29;
            this.button2.Text = "Export data to csv file";
            this.button2.UseVisualStyleBackColor = false;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.ForeColor = System.Drawing.Color.Yellow;
            this.label11.Location = new System.Drawing.Point(430, 99);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(52, 17);
            this.label11.TabIndex = 35;
            this.label11.Text = "Status:";
            // 
            // textBox1
            // 
            this.textBox1.BackColor = System.Drawing.Color.Black;
            this.textBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox1.ForeColor = System.Drawing.Color.Lime;
            this.textBox1.Location = new System.Drawing.Point(184, 80);
            this.textBox1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.textBox1.Name = "textBox1";
            this.textBox1.ReadOnly = true;
            this.textBox1.Size = new System.Drawing.Size(98, 30);
            this.textBox1.TabIndex = 34;
            this.textBox1.Text = "0";
            this.textBox1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // numRecLbl
            // 
            this.numRecLbl.AutoSize = true;
            this.numRecLbl.ForeColor = System.Drawing.Color.Yellow;
            this.numRecLbl.Location = new System.Drawing.Point(24, 90);
            this.numRecLbl.Name = "numRecLbl";
            this.numRecLbl.Size = new System.Drawing.Size(131, 17);
            this.numRecLbl.TabIndex = 33;
            this.numRecLbl.Text = "Number of Records";
            // 
            // numRecBar
            // 
            this.numRecBar.ForeColor = System.Drawing.Color.Red;
            this.numRecBar.Location = new System.Drawing.Point(305, 80);
            this.numRecBar.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.numRecBar.Name = "numRecBar";
            this.numRecBar.Size = new System.Drawing.Size(284, 17);
            this.numRecBar.TabIndex = 32;
            // 
            // rtEnabled
            // 
            this.rtEnabled.AutoSize = true;
            this.rtEnabled.Checked = true;
            this.rtEnabled.Location = new System.Drawing.Point(6, 21);
            this.rtEnabled.Name = "rtEnabled";
            this.rtEnabled.Size = new System.Drawing.Size(81, 21);
            this.rtEnabled.TabIndex = 36;
            this.rtEnabled.TabStop = true;
            this.rtEnabled.Text = "Enabled";
            this.rtEnabled.UseVisualStyleBackColor = true;
            // 
            // rtDisabled
            // 
            this.rtDisabled.AutoSize = true;
            this.rtDisabled.Location = new System.Drawing.Point(6, 48);
            this.rtDisabled.Name = "rtDisabled";
            this.rtDisabled.Size = new System.Drawing.Size(84, 21);
            this.rtDisabled.TabIndex = 37;
            this.rtDisabled.Text = "Disabled";
            this.rtDisabled.UseVisualStyleBackColor = true;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.rtEnabled);
            this.groupBox2.Controls.Add(this.rtDisabled);
            this.groupBox2.ForeColor = System.Drawing.Color.Aqua;
            this.groupBox2.Location = new System.Drawing.Point(15, 264);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(159, 79);
            this.groupBox2.TabIndex = 38;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Real TIme Reporting";
            // 
            // button4
            // 
            this.button4.BackColor = System.Drawing.Color.Black;
            this.button4.Enabled = false;
            this.button4.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button4.ForeColor = System.Drawing.Color.Yellow;
            this.button4.Location = new System.Drawing.Point(161, 128);
            this.button4.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(140, 114);
            this.button4.TabIndex = 39;
            this.button4.Text = "Erase the data from the unit";
            this.button4.UseVisualStyleBackColor = false;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Black;
            this.ClientSize = new System.Drawing.Size(601, 253);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.numRecLbl);
            this.Controls.Add(this.numRecBar);
            this.Controls.Add(this.dtTb);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.getDataBtn);
            this.Controls.Add(this.groupBox1);
            this.Name = "Form1";
            this.Text = "T.P. Monitor Rev 1.2";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label connStatusLbl;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.Button getDataBtn;
        private System.Windows.Forms.TextBox dtTb;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Label numRecLbl;
        private System.Windows.Forms.ProgressBar numRecBar;
        private System.Windows.Forms.RadioButton rtEnabled;
        private System.Windows.Forms.RadioButton rtDisabled;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.SaveFileDialog saveCSV;
    }
}

