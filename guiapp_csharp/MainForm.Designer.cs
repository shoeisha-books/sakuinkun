namespace SakuinKun
{
    partial class MainForm
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            ImportFileSelectLabel = new Label();
            ExportFileSelectLabel = new Label();
            RomanCapPagesLabel = new Label();
            StartNombreLabel = new Label();
            ImportFileNameTextBox = new TextBox();
            ExportFileNameTextBox = new TextBox();
            RomanPagesUpDown = new NumericUpDown();
            StartNombreUpDown = new NumericUpDown();
            RomanCapCheckBox = new CheckBox();
            ParseButton = new Button();
            ImportFileSelectButton = new Button();
            ExportFileSelectButton = new Button();
            MainMenu = new MenuStrip();
            FileMenuItem = new ToolStripMenuItem();
            JsonLoadMenuItem = new ToolStripMenuItem();
            toolStripSeparator1 = new ToolStripSeparator();
            ExitMenuItem = new ToolStripMenuItem();
            DicMenuItem = new ToolStripMenuItem();
            UserDicMenuItem = new ToolStripMenuItem();
            AboutMenuItem = new ToolStripMenuItem();
            RepeatLabel = new Label();
            RepeatComboBox = new ComboBox();
            ImportFileDialog = new OpenFileDialog();
            JsonLoadFileDialog = new OpenFileDialog();
            ExportFileDialog = new SaveFileDialog();
            MainStatusLabel = new ToolStripStatusLabel();
            MainStatusBar = new StatusStrip();
            ((System.ComponentModel.ISupportInitialize)RomanPagesUpDown).BeginInit();
            ((System.ComponentModel.ISupportInitialize)StartNombreUpDown).BeginInit();
            MainMenu.SuspendLayout();
            MainStatusBar.SuspendLayout();
            SuspendLayout();
            // 
            // ImportFileSelectLabel
            // 
            ImportFileSelectLabel.AutoSize = true;
            ImportFileSelectLabel.Location = new Point(12, 43);
            ImportFileSelectLabel.Name = "ImportFileSelectLabel";
            ImportFileSelectLabel.Size = new Size(99, 15);
            ImportFileSelectLabel.TabIndex = 1;
            ImportFileSelectLabel.Text = "読み込みファイル名";
            // 
            // ExportFileSelectLabel
            // 
            ExportFileSelectLabel.AutoSize = true;
            ExportFileSelectLabel.Enabled = false;
            ExportFileSelectLabel.Location = new Point(12, 72);
            ExportFileSelectLabel.Name = "ExportFileSelectLabel";
            ExportFileSelectLabel.Size = new Size(94, 15);
            ExportFileSelectLabel.TabIndex = 2;
            ExportFileSelectLabel.Text = "書き出しファイル名";
            ExportFileSelectLabel.Visible = false;
            // 
            // RomanCapPagesLabel
            // 
            RomanCapPagesLabel.AutoSize = true;
            RomanCapPagesLabel.Location = new Point(12, 100);
            RomanCapPagesLabel.Name = "RomanCapPagesLabel";
            RomanCapPagesLabel.Size = new Size(97, 15);
            RomanCapPagesLabel.TabIndex = 3;
            RomanCapPagesLabel.Text = "ローマ数字ページ数";
            // 
            // StartNombreLabel
            // 
            StartNombreLabel.AutoSize = true;
            StartNombreLabel.Location = new Point(12, 127);
            StartNombreLabel.Name = "StartNombreLabel";
            StartNombreLabel.Size = new Size(66, 15);
            StartNombreLabel.TabIndex = 4;
            StartNombreLabel.Text = "開始ノンブル";
            // 
            // ImportFileNameTextBox
            // 
            ImportFileNameTextBox.Enabled = false;
            ImportFileNameTextBox.Location = new Point(117, 40);
            ImportFileNameTextBox.Name = "ImportFileNameTextBox";
            ImportFileNameTextBox.Size = new Size(375, 23);
            ImportFileNameTextBox.TabIndex = 5;
            ImportFileNameTextBox.TextChanged += ImportFileNameTextBox_TextChanged;
            // 
            // ExportFileNameTextBox
            // 
            ExportFileNameTextBox.Enabled = false;
            ExportFileNameTextBox.Location = new Point(117, 69);
            ExportFileNameTextBox.Name = "ExportFileNameTextBox";
            ExportFileNameTextBox.Size = new Size(375, 23);
            ExportFileNameTextBox.TabIndex = 6;
            ExportFileNameTextBox.Visible = false;
            ExportFileNameTextBox.TextChanged += ExportFileNameTextBox_TextChanged;
            // 
            // RomanPagesUpDown
            // 
            RomanPagesUpDown.Location = new Point(117, 98);
            RomanPagesUpDown.Name = "RomanPagesUpDown";
            RomanPagesUpDown.Size = new Size(65, 23);
            RomanPagesUpDown.TabIndex = 7;
            // 
            // StartNombreUpDown
            // 
            StartNombreUpDown.Location = new Point(117, 127);
            StartNombreUpDown.Maximum = new decimal(new int[] { 1000, 0, 0, 0 });
            StartNombreUpDown.Minimum = new decimal(new int[] { 1, 0, 0, 0 });
            StartNombreUpDown.Name = "StartNombreUpDown";
            StartNombreUpDown.Size = new Size(65, 23);
            StartNombreUpDown.TabIndex = 8;
            StartNombreUpDown.Value = new decimal(new int[] { 1, 0, 0, 0 });
            // 
            // RomanCapCheckBox
            // 
            RomanCapCheckBox.AutoSize = true;
            RomanCapCheckBox.Checked = true;
            RomanCapCheckBox.CheckState = CheckState.Checked;
            RomanCapCheckBox.Location = new Point(188, 99);
            RomanCapCheckBox.Name = "RomanCapCheckBox";
            RomanCapCheckBox.Size = new Size(62, 19);
            RomanCapCheckBox.TabIndex = 9;
            RomanCapCheckBox.Text = "大文字";
            RomanCapCheckBox.UseVisualStyleBackColor = true;
            RomanCapCheckBox.CheckedChanged += RomanCapCheckBox_CheckedChanged;
            // 
            // ParseButton
            // 
            ParseButton.Location = new Point(431, 100);
            ParseButton.Name = "ParseButton";
            ParseButton.Size = new Size(95, 50);
            ParseButton.TabIndex = 10;
            ParseButton.Text = "Parse!";
            ParseButton.UseVisualStyleBackColor = true;
            ParseButton.Click += ParseButton_Click;
            // 
            // ImportFileSelectButton
            // 
            ImportFileSelectButton.Location = new Point(498, 40);
            ImportFileSelectButton.Name = "ImportFileSelectButton";
            ImportFileSelectButton.Size = new Size(28, 23);
            ImportFileSelectButton.TabIndex = 11;
            ImportFileSelectButton.Text = "...";
            ImportFileSelectButton.UseVisualStyleBackColor = true;
            ImportFileSelectButton.Click += ImportFileSelectButton_Click;
            // 
            // ExportFileSelectButton
            // 
            ExportFileSelectButton.Enabled = false;
            ExportFileSelectButton.Location = new Point(498, 68);
            ExportFileSelectButton.Name = "ExportFileSelectButton";
            ExportFileSelectButton.Size = new Size(28, 23);
            ExportFileSelectButton.TabIndex = 12;
            ExportFileSelectButton.Text = "...";
            ExportFileSelectButton.UseVisualStyleBackColor = true;
            ExportFileSelectButton.Visible = false;
            ExportFileSelectButton.Click += ExportFileSelectButton_Click;
            // 
            // MainMenu
            // 
            MainMenu.Items.AddRange(new ToolStripItem[] { FileMenuItem, DicMenuItem, AboutMenuItem });
            MainMenu.Location = new Point(0, 0);
            MainMenu.Name = "MainMenu";
            MainMenu.Size = new Size(544, 24);
            MainMenu.TabIndex = 13;
            MainMenu.Text = "menuStrip1";
            // 
            // FileMenuItem
            // 
            FileMenuItem.DropDownItems.AddRange(new ToolStripItem[] { JsonLoadMenuItem, toolStripSeparator1, ExitMenuItem });
            FileMenuItem.Name = "FileMenuItem";
            FileMenuItem.Size = new Size(67, 20);
            FileMenuItem.Text = "ファイル(&F)";
            // 
            // JsonLoadMenuItem
            // 
            JsonLoadMenuItem.Name = "JsonLoadMenuItem";
            JsonLoadMenuItem.Size = new Size(155, 22);
            JsonLoadMenuItem.Text = "Json読み込み(&J)";
            JsonLoadMenuItem.Click += JsonLoadMenuItem_Click;
            // 
            // toolStripSeparator1
            // 
            toolStripSeparator1.Name = "toolStripSeparator1";
            toolStripSeparator1.Size = new Size(152, 6);
            // 
            // ExitMenuItem
            // 
            ExitMenuItem.Name = "ExitMenuItem";
            ExitMenuItem.Size = new Size(155, 22);
            ExitMenuItem.Text = "終了(&X)";
            ExitMenuItem.Click += ExitMenuItem_Click;
            // 
            // DicMenuItem
            // 
            DicMenuItem.DropDownItems.AddRange(new ToolStripItem[] { UserDicMenuItem });
            DicMenuItem.Enabled = false;
            DicMenuItem.Name = "DicMenuItem";
            DicMenuItem.Size = new Size(59, 20);
            DicMenuItem.Text = "辞書(&D)";
            // 
            // UserDicMenuItem
            // 
            UserDicMenuItem.Name = "UserDicMenuItem";
            UserDicMenuItem.Size = new Size(177, 22);
            UserDicMenuItem.Text = "ユーザー辞書設定(&W)";
            // 
            // AboutMenuItem
            // 
            AboutMenuItem.Name = "AboutMenuItem";
            AboutMenuItem.Size = new Size(124, 20);
            AboutMenuItem.Text = "さくいんくんについて(&A)";
            AboutMenuItem.Click += AboutMenuItem_Click;
            // 
            // RepeatLabel
            // 
            RepeatLabel.AutoSize = true;
            RepeatLabel.Location = new Point(256, 99);
            RepeatLabel.Name = "RepeatLabel";
            RepeatLabel.Size = new Size(101, 15);
            RepeatLabel.TabIndex = 14;
            RepeatLabel.Text = "重複時の省略文字";
            // 
            // RepeatComboBox
            // 
            RepeatComboBox.DropDownStyle = ComboBoxStyle.DropDownList;
            RepeatComboBox.FormattingEnabled = true;
            RepeatComboBox.Location = new Point(286, 115);
            RepeatComboBox.Name = "RepeatComboBox";
            RepeatComboBox.Size = new Size(139, 23);
            RepeatComboBox.TabIndex = 15;
            RepeatComboBox.SelectedIndexChanged += RepeatComboBox_SelectedIndexChanged;
            // 
            // ImportFileDialog
            // 
            ImportFileDialog.FileName = "openFileDialog1";
            ImportFileDialog.FileOk += ImportFileDialog_FileOk;
            // 
            // JsonLoadFileDialog
            // 
            JsonLoadFileDialog.FileName = "openFileDialog2";
            // 
            // ExportFileDialog
            // 
            ExportFileDialog.FileOk += ExportFileDialog_FileOk;
            // 
            // MainStatusLabel
            // 
            MainStatusLabel.Name = "MainStatusLabel";
            MainStatusLabel.Size = new Size(0, 17);
            // 
            // MainStatusBar
            // 
            MainStatusBar.Items.AddRange(new ToolStripItem[] { MainStatusLabel });
            MainStatusBar.Location = new Point(0, 162);
            MainStatusBar.Name = "MainStatusBar";
            MainStatusBar.Size = new Size(544, 22);
            MainStatusBar.SizingGrip = false;
            MainStatusBar.TabIndex = 0;
            // 
            // MainForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(544, 184);
            Controls.Add(RepeatComboBox);
            Controls.Add(RepeatLabel);
            Controls.Add(ExportFileSelectButton);
            Controls.Add(ImportFileSelectButton);
            Controls.Add(ParseButton);
            Controls.Add(RomanCapCheckBox);
            Controls.Add(StartNombreUpDown);
            Controls.Add(RomanPagesUpDown);
            Controls.Add(ExportFileNameTextBox);
            Controls.Add(ImportFileNameTextBox);
            Controls.Add(StartNombreLabel);
            Controls.Add(RomanCapPagesLabel);
            Controls.Add(ExportFileSelectLabel);
            Controls.Add(ImportFileSelectLabel);
            Controls.Add(MainStatusBar);
            Controls.Add(MainMenu);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            MainMenuStrip = MainMenu;
            MaximizeBox = false;
            MinimizeBox = false;
            Name = "MainForm";
            Text = "さくいんくん";
            FormClosing += MainForm_FormClosing;
            Load += MainForm_Load;
            ((System.ComponentModel.ISupportInitialize)RomanPagesUpDown).EndInit();
            ((System.ComponentModel.ISupportInitialize)StartNombreUpDown).EndInit();
            MainMenu.ResumeLayout(false);
            MainMenu.PerformLayout();
            MainStatusBar.ResumeLayout(false);
            MainStatusBar.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion
        private Label ImportFileSelectLabel;
        private Label ExportFileSelectLabel;
        private Label RomanCapPagesLabel;
        private Label StartNombreLabel;
        private TextBox ImportFileNameTextBox;
        private TextBox ExportFileNameTextBox;
        private NumericUpDown RomanPagesUpDown;
        private NumericUpDown StartNombreUpDown;
        private CheckBox RomanCapCheckBox;
        private Button ParseButton;
        private Button ImportFileSelectButton;
        private Button ExportFileSelectButton;
        private MenuStrip MainMenu;
        private ToolStripMenuItem FileMenuItem;
        private ToolStripMenuItem AboutMenuItem;
        private ToolStripMenuItem JsonLoadMenuItem;
        private ToolStripMenuItem ExitMenuItem;
        private ToolStripMenuItem DicMenuItem;
        private ToolStripMenuItem UserDicMenuItem;
        private Label RepeatLabel;
        private ComboBox RepeatComboBox;
        private OpenFileDialog ImportFileDialog;
        private OpenFileDialog JsonLoadFileDialog;
        private SaveFileDialog ExportFileDialog;
        private StatusStrip MainStatusBar;
        private ToolStripStatusLabel MainStatusLabel;
        private ToolStripSeparator toolStripSeparator1;
    }
}
