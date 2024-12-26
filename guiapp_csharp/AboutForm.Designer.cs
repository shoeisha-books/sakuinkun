namespace SakuinKun
{
    partial class AboutForm
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
            label1 = new Label();
            AppVerLabel = new Label();
            label2 = new Label();
            label3 = new Label();
            AboutCopyButton = new Button();
            AboutCloseButton = new Button();
            label5 = new Label();
            label6 = new Label();
            LibSakuinVerLabel = new Label();
            MeCabModelVerLabel = new Label();
            MeCabTaggerVerLabel = new Label();
            label9 = new Label();
            BoostVerLabel = new Label();
            Xml2VerLabel = new Label();
            label4 = new Label();
            XlsxWriterVerLabel = new Label();
            label8 = new Label();
            label7 = new Label();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Yu Gothic UI", 16F);
            label1.Location = new Point(12, 9);
            label1.Name = "label1";
            label1.Size = new Size(108, 30);
            label1.TabIndex = 0;
            label1.Text = "さくいんくん";
            // 
            // AppVerLabel
            // 
            AppVerLabel.AutoSize = true;
            AppVerLabel.Location = new Point(198, 24);
            AppVerLabel.Name = "AppVerLabel";
            AppVerLabel.Size = new Size(31, 15);
            AppVerLabel.TabIndex = 1;
            AppVerLabel.Text = "x.x.x";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(50, 76);
            label2.Name = "label2";
            label2.Size = new Size(70, 15);
            label2.TabIndex = 2;
            label2.Text = "libsakuin.dll";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(50, 91);
            label3.Name = "label3";
            label3.Size = new Size(97, 15);
            label3.TabIndex = 3;
            label3.Text = "libmecab(Model)";
            // 
            // AboutCopyButton
            // 
            AboutCopyButton.Enabled = false;
            AboutCopyButton.Location = new Point(371, 136);
            AboutCopyButton.Name = "AboutCopyButton";
            AboutCopyButton.Size = new Size(75, 23);
            AboutCopyButton.TabIndex = 4;
            AboutCopyButton.Text = "コピー";
            AboutCopyButton.UseVisualStyleBackColor = true;
            AboutCopyButton.Click += AboutCopyButton_Click;
            // 
            // AboutCloseButton
            // 
            AboutCloseButton.Location = new Point(371, 165);
            AboutCloseButton.Name = "AboutCloseButton";
            AboutCloseButton.Size = new Size(75, 23);
            AboutCloseButton.TabIndex = 5;
            AboutCloseButton.Text = "OK";
            AboutCloseButton.UseVisualStyleBackColor = true;
            AboutCloseButton.Click += AboutCloseButton_Click;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(50, 121);
            label5.Name = "label5";
            label5.Size = new Size(37, 15);
            label5.TabIndex = 7;
            label5.Text = "boost";
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Location = new Point(50, 136);
            label6.Name = "label6";
            label6.Size = new Size(45, 15);
            label6.TabIndex = 8;
            label6.Text = "libxml2";
            // 
            // LibSakuinVerLabel
            // 
            LibSakuinVerLabel.AutoSize = true;
            LibSakuinVerLabel.Location = new Point(198, 76);
            LibSakuinVerLabel.Name = "LibSakuinVerLabel";
            LibSakuinVerLabel.Size = new Size(31, 15);
            LibSakuinVerLabel.TabIndex = 9;
            LibSakuinVerLabel.Text = "x.x.x";
            // 
            // MeCabModelVerLabel
            // 
            MeCabModelVerLabel.AutoSize = true;
            MeCabModelVerLabel.Location = new Point(198, 91);
            MeCabModelVerLabel.Name = "MeCabModelVerLabel";
            MeCabModelVerLabel.Size = new Size(31, 15);
            MeCabModelVerLabel.TabIndex = 10;
            MeCabModelVerLabel.Text = "x.x.x";
            // 
            // MeCabTaggerVerLabel
            // 
            MeCabTaggerVerLabel.AutoSize = true;
            MeCabTaggerVerLabel.Location = new Point(198, 106);
            MeCabTaggerVerLabel.Name = "MeCabTaggerVerLabel";
            MeCabTaggerVerLabel.Size = new Size(31, 15);
            MeCabTaggerVerLabel.TabIndex = 11;
            MeCabTaggerVerLabel.Text = "x.x.x";
            // 
            // label9
            // 
            label9.AutoSize = true;
            label9.Location = new Point(50, 106);
            label9.Name = "label9";
            label9.Size = new Size(98, 15);
            label9.TabIndex = 12;
            label9.Text = "libmecab(Tagger)";
            // 
            // BoostVerLabel
            // 
            BoostVerLabel.AutoSize = true;
            BoostVerLabel.Location = new Point(198, 121);
            BoostVerLabel.Name = "BoostVerLabel";
            BoostVerLabel.Size = new Size(31, 15);
            BoostVerLabel.TabIndex = 13;
            BoostVerLabel.Text = "x.x.x";
            // 
            // Xml2VerLabel
            // 
            Xml2VerLabel.AutoSize = true;
            Xml2VerLabel.Location = new Point(198, 136);
            Xml2VerLabel.Name = "Xml2VerLabel";
            Xml2VerLabel.Size = new Size(31, 15);
            Xml2VerLabel.TabIndex = 14;
            Xml2VerLabel.Text = "x.x.x";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(167, 24);
            label4.Name = "label4";
            label4.Size = new Size(25, 15);
            label4.TabIndex = 15;
            label4.Text = "ver.";
            // 
            // XlsxWriterVerLabel
            // 
            XlsxWriterVerLabel.AutoSize = true;
            XlsxWriterVerLabel.Location = new Point(198, 151);
            XlsxWriterVerLabel.Name = "XlsxWriterVerLabel";
            XlsxWriterVerLabel.Size = new Size(31, 15);
            XlsxWriterVerLabel.TabIndex = 17;
            XlsxWriterVerLabel.Text = "x.x.x";
            // 
            // label8
            // 
            label8.AutoSize = true;
            label8.Location = new Point(50, 151);
            label8.Name = "label8";
            label8.Size = new Size(57, 15);
            label8.TabIndex = 16;
            label8.Text = "xlsxwriter";
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Location = new Point(167, 39);
            label7.Name = "label7";
            label7.Size = new Size(138, 15);
            label7.TabIndex = 18;
            label7.Text = "©2024 Shoeisha Co., Ltd.";
            // 
            // AboutForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(458, 198);
            Controls.Add(label7);
            Controls.Add(XlsxWriterVerLabel);
            Controls.Add(label8);
            Controls.Add(label4);
            Controls.Add(Xml2VerLabel);
            Controls.Add(BoostVerLabel);
            Controls.Add(label9);
            Controls.Add(MeCabTaggerVerLabel);
            Controls.Add(MeCabModelVerLabel);
            Controls.Add(LibSakuinVerLabel);
            Controls.Add(label6);
            Controls.Add(label5);
            Controls.Add(AboutCloseButton);
            Controls.Add(AboutCopyButton);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(AppVerLabel);
            Controls.Add(label1);
            Name = "AboutForm";
            Text = "「さくいんくん」について";
            Load += AboutForm_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private Label AppVerLabel;
        private Label label2;
        private Label label3;
        private Button AboutCopyButton;
        private Button AboutCloseButton;
        private Label label5;
        private Label label6;
        private Label LibSakuinVerLabel;
        private Label MeCabModelVerLabel;
        private Label MeCabTaggerVerLabel;
        private Label label9;
        private Label BoostVerLabel;
        private Label Xml2VerLabel;
        private Label label4;
        private Label XlsxWriterVerLabel;
        private Label label8;
        private Label label7;
    }
}