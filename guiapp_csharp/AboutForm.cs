using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SakuinKun
{
    /// <summary>
    /// 「アプリについて」ウィンドウ
    /// </summary>
    public partial class AboutForm : Form
    {
        private class AboutViewModel : INotifyPropertyChanged
        {

            public string AppVer
            {
                get { return _appVer; }
                set
                {
                    if (_appVer != value)
                    {
                        _appVer = value;
                        OnPropertyChanged(nameof(AppVer));
                    }
                }
            }
            public string LibSakuinVer
            {
                get { return _libSakuinVer; }
                set
                {
                    if (_libSakuinVer != value)
                    {
                        _libSakuinVer = value;
                        OnPropertyChanged(nameof(LibSakuinVer));
                    }
                }
            }

            public string MeCabModelVer
            {
                get { return _mecabModelVer; }
                set
                {
                    if (_mecabModelVer != value)
                    {
                        _mecabModelVer = value;
                        OnPropertyChanged(nameof(MeCabModelVer));
                    }
                }
            }

            public string MeCabTaggerVer
            {
                get { return _mecabTaggerVer; }
                set
                {
                    if (_mecabTaggerVer != value)
                    {
                        _mecabTaggerVer = value;
                        OnPropertyChanged(nameof(MeCabTaggerVer));
                    }
                }
            }

            public string BoostVer
            {
                get { return _boostVer; }
                set
                {
                    if (_boostVer != value)
                    {
                        _boostVer = value;
                        OnPropertyChanged(nameof(BoostVer));
                    }
                }
            }

            public string Xml2Ver
            {
                get { return _xml2Ver; }
                set
                {
                    if (_xml2Ver != value)
                    {
                        _xml2Ver = value;
                        OnPropertyChanged(nameof(Xml2Ver));
                    }
                }
            }
            public string XlsxWriterVer
            {
                get { return _xlsxWriterVer; }
                set
                {
                    if (_xlsxWriterVer != value)
                    {
                        _xlsxWriterVer = value;
                        OnPropertyChanged(nameof(XlsxWriterVer));
                    }
                }
            }

            private string _appVer = string.Empty;
            private string _libSakuinVer = string.Empty;
            private string _mecabModelVer = string.Empty;
            private string _mecabTaggerVer = string.Empty;
            private string _boostVer = string.Empty;
            private string _xml2Ver = string.Empty;
            private string _xlsxWriterVer = string.Empty;

            public event PropertyChangedEventHandler? PropertyChanged;

            public void OnPropertyChanged(string propertyName)
            {
                if (PropertyChanged != null)
                {
                    PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
                }
            }
        }
        /// <summary>
        /// コンストラクタ
        /// </summary>
        public AboutForm()
        {
            InitializeComponent();
        }

        private void AboutCloseButton_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void CheckAppVer()
        {
            System.Diagnostics.FileVersionInfo ver =
                System.Diagnostics.FileVersionInfo.GetVersionInfo(
                System.Reflection.Assembly.GetExecutingAssembly().Location);
            var verStr = ver.FileVersion;
            aboutViewModel.AppVer = verStr!;
        }

        private void AboutForm_Load(object sender, EventArgs e)
        {
            AppVerLabel.DataBindings.Add("Text", aboutViewModel, "AppVer");
            LibSakuinVerLabel.DataBindings.Add("Text", aboutViewModel, "LibSakuinVer");
            MeCabModelVerLabel.DataBindings.Add("Text", aboutViewModel, "MeCabModelVer");
            MeCabTaggerVerLabel.DataBindings.Add("Text", aboutViewModel, "MeCabTaggerVer");
            BoostVerLabel.DataBindings.Add("Text", aboutViewModel, "BoostVer");
            Xml2VerLabel.DataBindings.Add("Text", aboutViewModel, "Xml2Ver");
            XlsxWriterVerLabel.DataBindings.Add("Text", aboutViewModel, "XlsxWriterVer");

            CheckAppVer();
            aboutViewModel.LibSakuinVer = LibSakuin.GetLibVersion();
            aboutViewModel.MeCabModelVer = LibSakuin.GetMeCabModelVersion();
            aboutViewModel.MeCabTaggerVer = LibSakuin.GetMeCabTaggerVersion();
            aboutViewModel.BoostVer = LibSakuin.GetBoostVersion();
            aboutViewModel.Xml2Ver = LibSakuin.GetXml2Version();
            aboutViewModel.XlsxWriterVer = LibSakuin.GetXlsxWriterVersion();
        }

        private readonly AboutViewModel aboutViewModel = new AboutViewModel();

        private void AboutCopyButton_Click(object sender, EventArgs e)
        {

        }
    }
}
