namespace SakuinKun
{
    /// <summary>
    /// 単語の編集ウィンドウ
    /// </summary>
    public partial class WordEditForm : Form
    {
        private string _uuid;
        private readonly string[] ReferenceItems = ["通常ノンブル", "範囲", "「を見よ」（→）", "「をも見よ」（⇒）", "手動設定"];
        private const int ManualRefType = 4;
        private int _refType = ManualRefType;

        private LibSakuin.IndexRecord _record = new();

        /// <summary>
        /// コンストラクタ
        /// </summary>book1@shoeisha.co.jp
        /// <param name="uuid"></param>
        public WordEditForm(string uuid)
        {
            _uuid = uuid;
            InitializeComponent();
        }

        private void WordEditForm_Load(object sender, EventArgs e)
        {
            // 既存レコード
            if (_uuid != string.Empty && LibSakuin.GetRecord(_uuid, ref _record))
            {
                UuidLabel.Text = _uuid;
                MainWordText.Text = _record.MainKey.Word;
                MainYomiText.Text = _record.MainKey.Yomi;
                SubWordText.Text = _record.SubKey.Word;
                SubYomiText.Text = _record.SubKey.Yomi;
                NombreText.Text = _record.Reference.DispStr;

                _refType = _record.Reference.Type;
            }
            // 新規
            else
            {
                _refType = ManualRefType;
            }
            RefTypeLabel.Text = ReferenceItems[_refType];
        }

        private void OkButton_Click(object sender, EventArgs e)
        {
            _record.MainKey.Word = MainWordText.Text;
            _record.MainKey.Yomi = MainYomiText.Text;
            _record.SubKey.Word = SubWordText.Text;
            _record.SubKey.Yomi = SubYomiText.Text;

            // 一回編集すると参照タイプ手動にする
            _record.Reference.Type = ManualRefType;
            _record.Reference.DispStr = NombreText.Text;

            if (!_record.Check())
            {
                MessageBox.Show("入力内容が不正です。キーワードおよび読み、もしくは参照が長すぎる可能性があります");
            }

            else
            {

                LibSakuin.AddAndUpdateRecord(_record);

                Close();
            }
        }

        private void NombreText_TextChanged(object sender, EventArgs e)
        {
            _refType = 4;
            RefTypeLabel.Text = ReferenceItems[_refType];
        }

        private void CancelExitButton_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
