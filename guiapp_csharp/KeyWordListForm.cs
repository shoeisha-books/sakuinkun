using System.ComponentModel;

namespace SakuinKun
{
    /// <summary>
    /// キーワード一覧ウィンドウ
    /// </summary>
    public partial class KeyWordListForm : Form
    {
        private bool _sort = false;
        private bool _yomiCheck = true;

        /// <summary>
        /// コンストラクタ
        /// </summary>
        public KeyWordListForm()
        {
            InitializeComponent();
        }

        private void KeyWordListForm_Load(object sender, EventArgs e)
        {
            UpdateGridView();
        }

        static private BindingList<DispKeyWord> ConvertIndex(LibSakuin.Index index)
        {
            BindingList<DispKeyWord> ret = new();
            for (int i = 0; i < index.Records.Count; i++)
            {
                var record = index.Records[i];
                DispKeyWord temp = new()
                {
                    MainKey = record.MainKey.Word,
                    MainYomi = record.MainKey.Yomi,
                    SubKey = record.SubKey.Word,
                    SubYomi = record.SubKey.Yomi,
                    //Page = record.Reference.Page,
                    Nombre = record.Reference.DispStr,
                    UUID = record.Uuid

                };
                ret.Add(temp);
            }
            return ret;
        }


        BindingList<DispKeyWord> _records = new();

        private void SortMenuItem_Click(object sender, EventArgs e)
        {
            _sort = !_sort;


            UpdateGridView();
        }

        private void UpdateGridView()
        {
            var recordNum = LibSakuin.GetIndexNum();
            var index = new LibSakuin.Index(recordNum);
            LibSakuin.GetIndex(ref index, _sort);

            _records = ConvertIndex(index);

            IndexRecordGridView.DataSource = _records;
            IndexRecordGridView.Refresh();

            YomiCheck();

        }

        private void YomiCheck()
        {
            if (!_yomiCheck)
            {
                return;
            }
            for (int i = 0; i < _records.Count; i++)
            {
                var record = _records[i];
                if (record.MainKey != record.MainYomi)
                {
                    IndexRecordGridView[1, i].Style.BackColor = Color.LightCoral;
                }
                if (record.SubKey != record.SubYomi)
                {
                    IndexRecordGridView[3, i].Style.BackColor = Color.LightCoral;
                }
            }
        }

        private void SaveJsonMenuItem_Click(object sender, EventArgs e)
        {
            var res = JsonSaveDialog.ShowDialog(this);
            if (res == DialogResult.OK)
            {
                var jsonFileName = JsonSaveDialog.FileName;
                LibSakuin.SaveJson(jsonFileName);

                //@TODO error
            }
        }

        private void ExitMenuItem_Click(object sender, EventArgs e)
        {
            // @TODO セーブチェック
            Close();
        }

        private void ExportXlsxMenuItem_Click(object sender, EventArgs e)
        {
            var res = XlsxExportDialog.ShowDialog(this);
            if (res == DialogResult.OK)
            {
                var xlsxFileName = XlsxExportDialog.FileName;
                LibSakuin.ExportXlsx(xlsxFileName);

                //@TOOD error
            }
        }

        private void AddKeyWordMenuItem_Click(object sender, EventArgs e)
        {
            var form = new WordEditForm("");
            form.ShowDialog();
            UpdateGridView();
        }

        private void YomiCheckMenuItem_Click(object sender, EventArgs e)
        {
            _yomiCheck = !_yomiCheck;
            UpdateGridView();
        }

        private void IndexRecordGridView_CellDoubleClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex < 0)
            {
                return;
            }
            var uuid = _records[e.RowIndex].UUID;

            var wordEditForm = new WordEditForm(uuid);
            wordEditForm.ShowDialog();
            UpdateGridView();
        }
    }
}
