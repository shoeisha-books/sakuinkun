namespace SakuinKun
{
    partial class KeyWordListForm
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
            components = new System.ComponentModel.Container();
            DataGridViewCellStyle dataGridViewCellStyle1 = new DataGridViewCellStyle();
            menuStrip1 = new MenuStrip();
            FileToolStripMenuItem = new ToolStripMenuItem();
            SaveJsonMenuItem = new ToolStripMenuItem();
            ExportXlsxMenuItem = new ToolStripMenuItem();
            toolStripSeparator1 = new ToolStripSeparator();
            ExitMenuItem = new ToolStripMenuItem();
            AddKeyWordMenuItem = new ToolStripMenuItem();
            SortMenuItem = new ToolStripMenuItem();
            YomiCheckMenuItem = new ToolStripMenuItem();
            IndexRecordGridView = new DataGridView();
            mainKeyDataGridViewTextBoxColumn = new DataGridViewTextBoxColumn();
            mainYomiDataGridViewTextBoxColumn = new DataGridViewTextBoxColumn();
            subKeyDataGridViewTextBoxColumn = new DataGridViewTextBoxColumn();
            subYomiDataGridViewTextBoxColumn = new DataGridViewTextBoxColumn();
            nombreDataGridViewTextBoxColumn = new DataGridViewTextBoxColumn();
            uUIDDataGridViewTextBoxColumn = new DataGridViewTextBoxColumn();
            keyWordBindingSource = new BindingSource(components);
            JsonSaveDialog = new SaveFileDialog();
            XlsxExportDialog = new SaveFileDialog();
            menuStrip1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)IndexRecordGridView).BeginInit();
            ((System.ComponentModel.ISupportInitialize)keyWordBindingSource).BeginInit();
            SuspendLayout();
            // 
            // menuStrip1
            // 
            menuStrip1.Items.AddRange(new ToolStripItem[] { FileToolStripMenuItem, AddKeyWordMenuItem, SortMenuItem, YomiCheckMenuItem });
            menuStrip1.Location = new Point(0, 0);
            menuStrip1.Name = "menuStrip1";
            menuStrip1.Size = new Size(1009, 24);
            menuStrip1.TabIndex = 0;
            // 
            // FileToolStripMenuItem
            // 
            FileToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { SaveJsonMenuItem, ExportXlsxMenuItem, toolStripSeparator1, ExitMenuItem });
            FileToolStripMenuItem.Name = "FileToolStripMenuItem";
            FileToolStripMenuItem.Size = new Size(67, 20);
            FileToolStripMenuItem.Text = "ファイル(&F)";
            // 
            // SaveJsonMenuItem
            // 
            SaveJsonMenuItem.Name = "SaveJsonMenuItem";
            SaveJsonMenuItem.Size = new Size(171, 22);
            SaveJsonMenuItem.Text = "Jsonで保存(&S)";
            SaveJsonMenuItem.Click += SaveJsonMenuItem_Click;
            // 
            // ExportXlsxMenuItem
            // 
            ExportXlsxMenuItem.Name = "ExportXlsxMenuItem";
            ExportXlsxMenuItem.Size = new Size(171, 22);
            ExportXlsxMenuItem.Text = "Xlsxにエクスポート(&E)";
            ExportXlsxMenuItem.Click += ExportXlsxMenuItem_Click;
            // 
            // toolStripSeparator1
            // 
            toolStripSeparator1.Name = "toolStripSeparator1";
            toolStripSeparator1.Size = new Size(168, 6);
            // 
            // ExitMenuItem
            // 
            ExitMenuItem.Name = "ExitMenuItem";
            ExitMenuItem.Size = new Size(171, 22);
            ExitMenuItem.Text = "終了(&X)";
            ExitMenuItem.Click += ExitMenuItem_Click;
            // 
            // AddKeyWordMenuItem
            // 
            AddKeyWordMenuItem.Name = "AddKeyWordMenuItem";
            AddKeyWordMenuItem.Size = new Size(83, 20);
            AddKeyWordMenuItem.Text = "項目追加(&A)";
            AddKeyWordMenuItem.Click += AddKeyWordMenuItem_Click;
            // 
            // SortMenuItem
            // 
            SortMenuItem.Name = "SortMenuItem";
            SortMenuItem.Size = new Size(99, 20);
            SortMenuItem.Text = "ソート切り替え(&S)";
            SortMenuItem.Click += SortMenuItem_Click;
            // 
            // YomiCheckMenuItem
            // 
            YomiCheckMenuItem.Name = "YomiCheckMenuItem";
            YomiCheckMenuItem.Size = new Size(90, 20);
            YomiCheckMenuItem.Text = "読みチェック(&C)";
            YomiCheckMenuItem.Visible = false;
            YomiCheckMenuItem.Click += YomiCheckMenuItem_Click;
            // 
            // IndexRecordGridView
            // 
            IndexRecordGridView.AllowUserToAddRows = false;
            IndexRecordGridView.AllowUserToDeleteRows = false;
            IndexRecordGridView.AutoGenerateColumns = false;
            IndexRecordGridView.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.AllCells;
            IndexRecordGridView.AutoSizeRowsMode = DataGridViewAutoSizeRowsMode.AllCells;
            IndexRecordGridView.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            IndexRecordGridView.Columns.AddRange(new DataGridViewColumn[] { mainKeyDataGridViewTextBoxColumn, mainYomiDataGridViewTextBoxColumn, subKeyDataGridViewTextBoxColumn, subYomiDataGridViewTextBoxColumn, nombreDataGridViewTextBoxColumn, uUIDDataGridViewTextBoxColumn });
            IndexRecordGridView.DataSource = keyWordBindingSource;
            dataGridViewCellStyle1.Alignment = DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle1.BackColor = SystemColors.Window;
            dataGridViewCellStyle1.Font = new Font("Yu Gothic UI", 12F, FontStyle.Regular, GraphicsUnit.Point, 128);
            dataGridViewCellStyle1.ForeColor = SystemColors.ControlText;
            dataGridViewCellStyle1.SelectionBackColor = SystemColors.Highlight;
            dataGridViewCellStyle1.SelectionForeColor = SystemColors.HighlightText;
            dataGridViewCellStyle1.WrapMode = DataGridViewTriState.False;
            IndexRecordGridView.DefaultCellStyle = dataGridViewCellStyle1;
            IndexRecordGridView.Dock = DockStyle.Fill;
            IndexRecordGridView.Location = new Point(0, 24);
            IndexRecordGridView.Name = "IndexRecordGridView";
            IndexRecordGridView.ReadOnly = true;
            IndexRecordGridView.RowHeadersVisible = false;
            IndexRecordGridView.Size = new Size(1009, 535);
            IndexRecordGridView.TabIndex = 1;
            IndexRecordGridView.CellDoubleClick += IndexRecordGridView_CellDoubleClick;
            // 
            // mainKeyDataGridViewTextBoxColumn
            // 
            mainKeyDataGridViewTextBoxColumn.AutoSizeMode = DataGridViewAutoSizeColumnMode.Fill;
            mainKeyDataGridViewTextBoxColumn.DataPropertyName = "MainKey";
            mainKeyDataGridViewTextBoxColumn.HeaderText = "メインキー";
            mainKeyDataGridViewTextBoxColumn.Name = "mainKeyDataGridViewTextBoxColumn";
            mainKeyDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // mainYomiDataGridViewTextBoxColumn
            // 
            mainYomiDataGridViewTextBoxColumn.AutoSizeMode = DataGridViewAutoSizeColumnMode.Fill;
            mainYomiDataGridViewTextBoxColumn.DataPropertyName = "MainYomi";
            mainYomiDataGridViewTextBoxColumn.HeaderText = "メイン読み";
            mainYomiDataGridViewTextBoxColumn.Name = "mainYomiDataGridViewTextBoxColumn";
            mainYomiDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // subKeyDataGridViewTextBoxColumn
            // 
            subKeyDataGridViewTextBoxColumn.AutoSizeMode = DataGridViewAutoSizeColumnMode.Fill;
            subKeyDataGridViewTextBoxColumn.DataPropertyName = "SubKey";
            subKeyDataGridViewTextBoxColumn.HeaderText = "サブキー";
            subKeyDataGridViewTextBoxColumn.Name = "subKeyDataGridViewTextBoxColumn";
            subKeyDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // subYomiDataGridViewTextBoxColumn
            // 
            subYomiDataGridViewTextBoxColumn.AutoSizeMode = DataGridViewAutoSizeColumnMode.Fill;
            subYomiDataGridViewTextBoxColumn.DataPropertyName = "SubYomi";
            subYomiDataGridViewTextBoxColumn.HeaderText = "サブ読み";
            subYomiDataGridViewTextBoxColumn.Name = "subYomiDataGridViewTextBoxColumn";
            subYomiDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // nombreDataGridViewTextBoxColumn
            // 
            nombreDataGridViewTextBoxColumn.AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCells;
            nombreDataGridViewTextBoxColumn.DataPropertyName = "Nombre";
            nombreDataGridViewTextBoxColumn.HeaderText = "ノンブル";
            nombreDataGridViewTextBoxColumn.Name = "nombreDataGridViewTextBoxColumn";
            nombreDataGridViewTextBoxColumn.ReadOnly = true;
            nombreDataGridViewTextBoxColumn.Width = 67;
            // 
            // uUIDDataGridViewTextBoxColumn
            // 
            uUIDDataGridViewTextBoxColumn.DataPropertyName = "UUID";
            uUIDDataGridViewTextBoxColumn.HeaderText = "UUID";
            uUIDDataGridViewTextBoxColumn.Name = "uUIDDataGridViewTextBoxColumn";
            uUIDDataGridViewTextBoxColumn.ReadOnly = true;
            uUIDDataGridViewTextBoxColumn.Visible = false;
            uUIDDataGridViewTextBoxColumn.Width = 59;
            // 
            // keyWordBindingSource
            // 
            keyWordBindingSource.DataSource = typeof(DispKeyWord);
            // 
            // JsonSaveDialog
            // 
            JsonSaveDialog.CheckPathExists = false;
            JsonSaveDialog.CheckWriteAccess = false;
            JsonSaveDialog.DefaultExt = "json";
            JsonSaveDialog.Filter = "Jsonファイル|*.json";
            // 
            // XlsxExportDialog
            // 
            XlsxExportDialog.CheckPathExists = false;
            XlsxExportDialog.CheckWriteAccess = false;
            XlsxExportDialog.DefaultExt = "xlsx";
            XlsxExportDialog.Filter = "Excelファイル|*.xlsx";
            // 
            // KeyWordListForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1009, 559);
            Controls.Add(IndexRecordGridView);
            Controls.Add(menuStrip1);
            MainMenuStrip = menuStrip1;
            Name = "KeyWordListForm";
            Text = "キーワード一覧（ダブルクリックで編集）";
            Load += KeyWordListForm_Load;
            menuStrip1.ResumeLayout(false);
            menuStrip1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)IndexRecordGridView).EndInit();
            ((System.ComponentModel.ISupportInitialize)keyWordBindingSource).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private MenuStrip menuStrip1;
        private DataGridView IndexRecordGridView;
        private ToolStripMenuItem SortMenuItem;
        private ToolStripMenuItem FileToolStripMenuItem;
        private ToolStripMenuItem SaveJsonMenuItem;
        private ToolStripMenuItem ExportXlsxMenuItem;
        private ToolStripMenuItem YomiCheckMenuItem;
        private SaveFileDialog JsonSaveDialog;
        private SaveFileDialog XlsxExportDialog;
        private ToolStripSeparator toolStripSeparator1;
        private ToolStripMenuItem ExitMenuItem;
        private ToolStripMenuItem AddKeyWordMenuItem;
        private DataGridViewTextBoxColumn mainKeyDataGridViewTextBoxColumn;
        private DataGridViewTextBoxColumn mainYomiDataGridViewTextBoxColumn;
        private DataGridViewTextBoxColumn subKeyDataGridViewTextBoxColumn;
        private DataGridViewTextBoxColumn subYomiDataGridViewTextBoxColumn;
        private DataGridViewTextBoxColumn nombreDataGridViewTextBoxColumn;
        private DataGridViewTextBoxColumn uUIDDataGridViewTextBoxColumn;
        private BindingSource keyWordBindingSource;
    }
}