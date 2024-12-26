using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WinRT;
using static SakuinKun.LibSakuin;

namespace SakuinKun
{
    public partial class KeyWordListForm : Form
    {
        private bool _sort = false;
        private bool _yomiCheck = true;

        public KeyWordListForm()
        {
            InitializeComponent();
        }

        public void ImportXml(string importFileName)
        {
            if (!LibSakuin.ImportXml(importFileName))
            {
                // @TODO error
                return;
            }
        }

        public void LoadJson(string jsonFileName)
        {
            if (!LibSakuin.LoadJson(jsonFileName))
            {
                // @TODO error
                return;
            }
        }

        private void KeyWordListForm_Load(object sender, EventArgs e)
        {
            UpdateGridView();
        }

        private BindingList<IndexDispRecord> ConvertIndex(LibSakuin.Index index)
        {
            BindingList<IndexDispRecord> ret = new();
            for (int i = 0; i < index.Records.Count; i++)
            {
                var record = index.Records[i];
                IndexDispRecord temp = new()
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

        internal class IndexDispRecord
        {
            public string MainKey { get; set; } = string.Empty;
            public string MainYomi { get; set; } = string.Empty;
            public string SubKey { get; set; } = string.Empty;
            public string SubYomi { get; set; } = string.Empty;
            //public int Page { get; set; }
            public string Nombre { get; set; } = string.Empty;

            public string UUID { get; set; } = string.Empty;
        }
        BindingList<IndexDispRecord> _records = new();

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

            IndexRecordGridView.DataSource = null;
            IndexRecordGridView.DataSource = _records;

            IndexRecordGridView.Columns[0].HeaderText = "メインキー";
            IndexRecordGridView.Columns[1].HeaderText = "メインキー読み";
            IndexRecordGridView.Columns[2].HeaderText = "サブキー";
            IndexRecordGridView.Columns[3].HeaderText = "サブキー読み";

            IndexRecordGridView.Columns[4].HeaderText = "ノンブル";

            IndexRecordGridView.Columns[5].Visible = false;
            IndexRecordGridView.Columns[5].HeaderText = "UUID";

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

        private void IndexRecordGridView_CellContentDoubleClick(object sender, DataGridViewCellEventArgs e)
        {
            var uuid = _records[e.RowIndex].UUID;

            var wordEditForm = new WordEditForm(uuid);
            wordEditForm.ShowDialog();
            UpdateGridView();
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
    }
}
