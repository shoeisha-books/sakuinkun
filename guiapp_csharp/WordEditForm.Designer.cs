namespace SakuinKun
{
    partial class WordEditForm
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
            OkButton = new Button();
            groupBox1 = new GroupBox();
            MainYomiText = new TextBox();
            label2 = new Label();
            MainWordText = new TextBox();
            label1 = new Label();
            groupBox2 = new GroupBox();
            SubYomiText = new TextBox();
            label6 = new Label();
            SubWordText = new TextBox();
            label7 = new Label();
            groupBox3 = new GroupBox();
            RefTypeLabel = new Label();
            label4 = new Label();
            label3 = new Label();
            NombreText = new TextBox();
            label5 = new Label();
            label8 = new Label();
            UuidLabel = new Label();
            CancelExitButton = new Button();
            groupBox1.SuspendLayout();
            groupBox2.SuspendLayout();
            groupBox3.SuspendLayout();
            SuspendLayout();
            // 
            // OkButton
            // 
            OkButton.Location = new Point(306, 199);
            OkButton.Name = "OkButton";
            OkButton.Size = new Size(75, 23);
            OkButton.TabIndex = 0;
            OkButton.Text = "OK";
            OkButton.UseVisualStyleBackColor = true;
            OkButton.Click += OkButton_Click;
            // 
            // groupBox1
            // 
            groupBox1.Controls.Add(MainYomiText);
            groupBox1.Controls.Add(label2);
            groupBox1.Controls.Add(MainWordText);
            groupBox1.Controls.Add(label1);
            groupBox1.Location = new Point(18, 12);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new Size(200, 100);
            groupBox1.TabIndex = 11;
            groupBox1.TabStop = false;
            groupBox1.Text = "メインキーワード";
            // 
            // MainYomiText
            // 
            MainYomiText.Location = new Point(72, 53);
            MainYomiText.Name = "MainYomiText";
            MainYomiText.Size = new Size(100, 23);
            MainYomiText.TabIndex = 8;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(28, 56);
            label2.Name = "label2";
            label2.Size = new Size(30, 15);
            label2.TabIndex = 7;
            label2.Text = "読み";
            // 
            // MainWordText
            // 
            MainWordText.Location = new Point(72, 24);
            MainWordText.Name = "MainWordText";
            MainWordText.Size = new Size(100, 23);
            MainWordText.TabIndex = 6;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(28, 27);
            label1.Name = "label1";
            label1.Size = new Size(31, 15);
            label1.TabIndex = 5;
            label1.Text = "単語";
            // 
            // groupBox2
            // 
            groupBox2.Controls.Add(SubYomiText);
            groupBox2.Controls.Add(label6);
            groupBox2.Controls.Add(SubWordText);
            groupBox2.Controls.Add(label7);
            groupBox2.Location = new Point(18, 118);
            groupBox2.Name = "groupBox2";
            groupBox2.Size = new Size(200, 100);
            groupBox2.TabIndex = 12;
            groupBox2.TabStop = false;
            groupBox2.Text = "サブキーワード";
            // 
            // SubYomiText
            // 
            SubYomiText.Location = new Point(72, 53);
            SubYomiText.Name = "SubYomiText";
            SubYomiText.Size = new Size(100, 23);
            SubYomiText.TabIndex = 8;
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Location = new Point(28, 56);
            label6.Name = "label6";
            label6.Size = new Size(30, 15);
            label6.TabIndex = 7;
            label6.Text = "読み";
            // 
            // SubWordText
            // 
            SubWordText.Location = new Point(72, 24);
            SubWordText.Name = "SubWordText";
            SubWordText.Size = new Size(100, 23);
            SubWordText.TabIndex = 6;
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Location = new Point(28, 27);
            label7.Name = "label7";
            label7.Size = new Size(31, 15);
            label7.TabIndex = 5;
            label7.Text = "単語";
            // 
            // groupBox3
            // 
            groupBox3.Controls.Add(RefTypeLabel);
            groupBox3.Controls.Add(label4);
            groupBox3.Controls.Add(label3);
            groupBox3.Controls.Add(NombreText);
            groupBox3.Controls.Add(label5);
            groupBox3.Location = new Point(224, 12);
            groupBox3.Name = "groupBox3";
            groupBox3.Size = new Size(200, 118);
            groupBox3.TabIndex = 13;
            groupBox3.TabStop = false;
            groupBox3.Text = "ノンブル・参照";
            // 
            // RefTypeLabel
            // 
            RefTypeLabel.AutoSize = true;
            RefTypeLabel.Location = new Point(82, 33);
            RefTypeLabel.Name = "RefTypeLabel";
            RefTypeLabel.Size = new Size(42, 15);
            RefTypeLabel.TabIndex = 17;
            RefTypeLabel.Text = "Invalid";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("Yu Gothic UI", 8.25F, FontStyle.Regular, GraphicsUnit.Point, 128);
            label4.Location = new Point(18, 87);
            label4.Name = "label4";
            label4.Size = new Size(55, 13);
            label4.TabIndex = 16;
            label4.Text = "ノンブルなど";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(18, 33);
            label3.Name = "label3";
            label3.Size = new Size(58, 15);
            label3.TabIndex = 14;
            label3.Text = "参照タイプ";
            // 
            // NombreText
            // 
            NombreText.Location = new Point(82, 77);
            NombreText.Name = "NombreText";
            NombreText.Size = new Size(100, 23);
            NombreText.TabIndex = 12;
            NombreText.TextChanged += NombreText_TextChanged;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(18, 72);
            label5.Name = "label5";
            label5.Size = new Size(31, 15);
            label5.TabIndex = 11;
            label5.Text = "内容";
            // 
            // label8
            // 
            label8.AutoSize = true;
            label8.Location = new Point(230, 156);
            label8.Name = "label8";
            label8.Size = new Size(34, 15);
            label8.TabIndex = 14;
            label8.Text = "UUID";
            // 
            // UuidLabel
            // 
            UuidLabel.AutoSize = true;
            UuidLabel.Location = new Point(230, 171);
            UuidLabel.Name = "UuidLabel";
            UuidLabel.Size = new Size(219, 15);
            UuidLabel.TabIndex = 15;
            UuidLabel.Text = "00000000-0000-0000-0000-000000000000";
            // 
            // CancelExitButton
            // 
            CancelExitButton.Location = new Point(393, 199);
            CancelExitButton.Name = "CancelExitButton";
            CancelExitButton.Size = new Size(75, 23);
            CancelExitButton.TabIndex = 16;
            CancelExitButton.Text = "キャンセル";
            CancelExitButton.UseVisualStyleBackColor = true;
            // 
            // WordEditForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(480, 234);
            Controls.Add(CancelExitButton);
            Controls.Add(UuidLabel);
            Controls.Add(label8);
            Controls.Add(groupBox3);
            Controls.Add(groupBox2);
            Controls.Add(groupBox1);
            Controls.Add(OkButton);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            MaximizeBox = false;
            MinimizeBox = false;
            Name = "WordEditForm";
            Text = "キーワード編集";
            Load += WordEditForm_Load;
            groupBox1.ResumeLayout(false);
            groupBox1.PerformLayout();
            groupBox2.ResumeLayout(false);
            groupBox2.PerformLayout();
            groupBox3.ResumeLayout(false);
            groupBox3.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button OkButton;
        private GroupBox groupBox1;
        private TextBox MainYomiText;
        private Label label2;
        private TextBox MainWordText;
        private Label label1;
        private GroupBox groupBox2;
        private TextBox SubYomiText;
        private Label label6;
        private TextBox SubWordText;
        private Label label7;
        private GroupBox groupBox3;
        private Label label3;
        private TextBox NombreText;
        private Label label5;
        private Label label4;
        private Label label8;
        private Label UuidLabel;
        private Label RefTypeLabel;
        private Button CancelExitButton;
    }
}