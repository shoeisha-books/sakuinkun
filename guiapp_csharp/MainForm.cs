using WinRT;

namespace SakuinKun
{
    /// <summary>
    /// メインウィンドウ
    /// </summary>
    public partial class MainForm : Form
    {
        private readonly string[] RepeatItems = ["――（2倍ダーシ）", "―（ダーシ）", "～（波）"];
        private readonly string[] Repeats = ["――", "―", "～"];
        private readonly int RepeatItemDefaultIndex = 2;

        /// <summary>
        /// コンストラクタ
        /// </summary>
        public MainForm()
        {
            InitializeComponent();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            InitializeLib();

            CheckAppVer();

            RepeatComboBox.Items.AddRange(RepeatItems);
            RepeatComboBox.SelectedIndex = RepeatItemDefaultIndex;
            CheckParseButtonEnable();
        }

        private void MainForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            LibSakuin.Dispose();
        }


        private void CheckAppVer()
        {
            System.Diagnostics.FileVersionInfo ver =
                System.Diagnostics.FileVersionInfo.GetVersionInfo(
                System.Reflection.Assembly.GetExecutingAssembly().Location);
            var verStr = ver.FileVersion;
            Text = "さくいんくん ver." + verStr;
        }

        private void ExitMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void ExportFileDialog_FileOk(object sender, System.ComponentModel.CancelEventArgs e)
        {
            ExportFileNameTextBox.Text = sender.As<SaveFileDialog>().FileName;
        }

        private void RepeatComboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            CheckParseButtonEnable();
        }

        private void RomanCapCheckBox_CheckedChanged(object sender, EventArgs e)
        {
            CheckParseButtonEnable();
        }

        void CheckParseButtonEnable()
        {
            // ファイル名がセットされている
            ParseButton.Enabled = (ImportFileNameTextBox.Text != ""
                //&& ExportFileNameTextBox.Text != "");
                );

        }

        private void ImportFileNameTextBox_TextChanged(object sender, EventArgs e)
        {
            CheckParseButtonEnable();
        }

        private void ExportFileNameTextBox_TextChanged(object sender, EventArgs e)
        {
            CheckParseButtonEnable();
        }

        private void ImportFileSelectButton_Click(object sender, EventArgs e)
        {
            ImportFileDialog.Filter = "Acrobat注釈ファイル(*.xfdf)|*.xfdf";
            ImportFileDialog.ShowDialog();
        }

        private void ImportFileDialog_FileOk(object sender, System.ComponentModel.CancelEventArgs e)
        {
            ImportFileNameTextBox.Text = sender.As<OpenFileDialog>().FileName;
        }

        private void ExportFileSelectButton_Click(object sender, EventArgs e)
        {
            ExportFileDialog.Filter = "Excelドキュメント(*.xlsx)|*.xlsx";
            ExportFileDialog.ShowDialog();
        }

        private void JsonLoadMenuItem_Click(object sender, EventArgs e)
        {
            JsonLoadFileDialog.Filter = "JSONファイル(*.json)|*.json";
            if (JsonLoadFileDialog.ShowDialog() == DialogResult.OK)
            {
                var wordListForm = new KeyWordListForm();
                if (!LibSakuin.LoadJson(JsonLoadFileDialog.FileName))
                {
                    // @TODO error
                    MessageBox.Show("不正なJsonファイルです");
                    return;
                }
                Visible = false;
                wordListForm.ShowDialog();
                Visible = true;
            }
        }

        private void AboutMenuItem_Click(object sender, EventArgs e)
        {
            var aboutForm = new AboutForm();
            aboutForm.ShowDialog();
        }

        private bool InitializeLib()
        {
            LibSakuin.InitSakuin();
            return false;
        }

        private void ParseButton_Click(object sender, EventArgs e)
        {
            var desc = new LibSakuin.IndexDesc
            {
                RomanCap = RomanCapCheckBox.Checked,

                Offset = decimal.ToInt32(StartNombreUpDown.Value),
                RomanPageNum = decimal.ToInt32(RomanPagesUpDown.Value),

                Repeat = Repeats[RepeatComboBox.SelectedIndex]
            };

            LibSakuin.SetDesc(desc);
            if (!LibSakuin.ImportXml(ImportFileNameTextBox.Text))
            {
                // @TODO error
                return;
            }


            var listForm = new KeyWordListForm();
            Visible = false;
            var listResult = listForm.ShowDialog(this);
            Visible = true;
        }
    }
}
