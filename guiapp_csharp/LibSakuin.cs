using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.Metadata;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using Windows.Media;
using WinRT;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace SakuinKun
{
    internal class LibSakuin
    {
        private const string DllName = "libsakuin.dll";

        private static readonly int VersionLength = 32;
        private static readonly int RepeatMaxLength = 16;
        private static readonly int KeyWordMaxLength = 128;
        private static readonly int DispStrMaxLength = 128;

        public class IndexDesc
        {
            public string Repeat { get; set; } = string.Empty;
            public int Offset { get; set; } = 0;
            public int RomanPageNum { get; set; } = 0;
            public bool RomanCap { get; set; } = true;

            [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Unicode)]
            public struct Data
            {
                public IntPtr repeat;
                public int repeatLen;
                public int offset;
                public int romanPageNum;
                public bool romanCap;
            }

            public Data AllocData()
            {
                Data data = new Data() { repeatLen = Repeat.Length, offset = Offset, romanPageNum = RomanPageNum, romanCap = RomanCap };
                var rep = Repeat;
                data.repeat = Marshal.StringToHGlobalUni(rep);
                return data;
            }

            static public void FreeData(Data data)
            {
                Marshal.FreeHGlobal(data.repeat);
            }

            public void SetData(Data data)
            {
                Repeat = Marshal.PtrToStringUni(data.repeat) ?? string.Empty;
                Offset = data.offset;
                RomanPageNum = data.romanPageNum;
                RomanCap = data.romanCap;
            }
        }

        public class KeyWord
        {
            public string Word { get; set; } = string.Empty;
            public string Yomi { get; set; } = string.Empty;

            [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Unicode)]
            public struct Data
            {
                public IntPtr word;
                public IntPtr yomi;
                public int word_len;
                public int yomi_len;
            }

            public Data AllocRecvData()
            {
                Data data = new Data() { word_len = KeyWordMaxLength, yomi_len = KeyWordMaxLength};
                var memSize = Marshal.SizeOf<char>() * KeyWordMaxLength;
                data.word = Marshal.AllocHGlobal(memSize);
                data.yomi = Marshal.AllocHGlobal(memSize);

                return data;
            }

            public Data AllocSendData()
            {
                Data data = new Data() { word_len = Word.Length, yomi_len = Yomi.Length };
                data.word = Marshal.StringToHGlobalUni(Word);
                data.yomi = Marshal.StringToHGlobalUni(Yomi);

                return data;
            }


            static public void FreeData(Data data)
            {
                Marshal.FreeHGlobal(data.word);
                Marshal.FreeHGlobal(data.yomi);
            }

            public void SetData(Data data)
            {
                Word = Marshal.PtrToStringUni(data.word) ?? string.Empty;
                Yomi = Marshal.PtrToStringUni(data.yomi) ?? string.Empty;
            }

            public bool Check()
            {
                // 余裕を持って
                return Word.Length < KeyWordMaxLength - 5 && Yomi.Length < KeyWordMaxLength - 5;
            }
        }

        public class Reference
        {
            public string DispStr { get; set; } = string.Empty;
            public int Type { get; set; } = 0;
            public int Page { get; set; } = 0;

            [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Unicode)]
            public struct Data
            {
                public IntPtr disp_str;
                public int disp_str_len;
                public int type;
                public int page;
            }

            public Data AllocRecvData()
            {
                Data data = new()
                {
                    disp_str_len = DispStrMaxLength,
                    type = Type,
                    page = Page
                };
                var memSize = Marshal.SizeOf<char>() * DispStrMaxLength;
                data.disp_str = Marshal.AllocHGlobal(memSize);
                

                return data;
            }

            public Data AllocSendData()
            {
                Data data = new()
                {
                    disp_str_len = DispStr.Length,
                    type = Type,
                    page = Page
                };
                data.disp_str = Marshal.StringToHGlobalUni(DispStr);


                return data;
            }


            static public void FreeData(Data data)
            {
                Marshal.FreeHGlobal(data.disp_str);
            }

            public void SetData(Data data)
            {
                DispStr = Marshal.PtrToStringUni(data.disp_str) ?? string.Empty;
                Type = data.type;
                Page = data.page;
            }

            public bool Check()
            {
                return DispStr.Length < DispStrMaxLength;
            }
        }

        public class IndexRecord
        {
            public KeyWord MainKey { get; set; } = new();
            public KeyWord SubKey { get; set; } = new();
            public Reference Reference { get; set; } = new();
            public string Uuid { get; set; } = "00000000-0000-0000-0000-000000000000";

            [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Unicode)]
            public struct Data
            {
                public KeyWord.Data main_key;
                public KeyWord.Data sub_key;
                public Reference.Data reference;
                public IntPtr uuid;
                public int uuid_len;
                public bool has_sub_key;
            }
            public Data AllocRecvData()
            {
                Data data = new Data()
                {
                    main_key = MainKey.AllocRecvData(),
                    sub_key = SubKey.AllocRecvData(),
                    reference = Reference.AllocRecvData(),
                    uuid_len = Uuid.Length
                };
                data.uuid = Marshal.StringToHGlobalUni(Uuid);

                return data;
            }

            public Data AllocSendData()
            {
                Data data = new Data()
                {
                    main_key = MainKey.AllocSendData(),
                    sub_key = SubKey.AllocSendData(),
                    reference = Reference.AllocSendData(),
                    uuid_len = Uuid.Length,
                    has_sub_key = (SubKey.Word != string.Empty)
                };
                data.uuid = Marshal.StringToHGlobalUni(Uuid);

                return data;
            }

            static public void FreeData(Data data)
            {
                KeyWord.FreeData(data.main_key);
                KeyWord.FreeData(data.sub_key);
                Reference.FreeData(data.reference);
                Marshal.FreeHGlobal(data.uuid);
            }

            public void SetData(Data data)
            {
                MainKey.SetData(data.main_key);
                if (data.has_sub_key)
                {
                    SubKey.SetData(data.sub_key);
                }
                else
                {
                    SubKey = new();
                }
                Reference.SetData(data.reference);
                Uuid = Marshal.PtrToStringUni(data.uuid) ?? string.Empty;
            }

            public bool Check()
            {
                return MainKey.Check() && SubKey.Check() && Reference.Check();
            }
        }

        public class Index
        {
            public Index(int recordCount)
            {
                for (int i = 0; i < recordCount; i++)
                {
                    Records.Add(new IndexRecord());
                }
            }
            public IndexDesc Desc { get; set; } = new();
            public List<IndexRecord> Records { get; set; } = new();

            [StructLayout(LayoutKind.Sequential, CharSet=CharSet.Unicode)]
            public struct Data
            {
                public IndexDesc.Data desc;
                public IntPtr records;
                public int records_num;
            }

            public Data AllocRecvData()
            {
                Data data = new Data()
                {
                    desc = Desc.AllocData(),
                    records_num = Records.Count
                };
                var memSize = Marshal.SizeOf<IndexRecord.Data>();
                data.records = Marshal.AllocHGlobal(memSize * Records.Count);
                for (int i = 0; i < Records.Count; i++)
                {
                    Marshal.StructureToPtr(Records[i].AllocRecvData(), data.records + i * memSize, false);
                }

                return data;
            }

            static public void FreeData(Data data)
            {
                Marshal.FreeHGlobal(data.records);
            }

            public void SetData(Data data)
            {
                Desc.SetData(data.desc);
                Records.Clear();
                var memSize = Marshal.SizeOf<IndexRecord.Data>();
                for (int i = 0; i < data.records_num; i++)
                {
                    IndexRecord.Data temp =
                        Marshal.PtrToStructure(data.records + i * memSize, typeof(IndexRecord.Data))
                        .As<IndexRecord.Data>();

                    IndexRecord record = new();
                    record.SetData(temp);
                    Records.Add(record);
                }
            }
        }


        public static void InitSakuin()
        {
            [DllImport(DllName)]
            static extern void initialize();

            initialize();
        }

        public static bool IsInitialized()
        {
            [DllImport(DllName)]
            static extern bool is_initialized();

            return is_initialized();
        }

        public static bool LoadJson(string path)
        {
            [DllImport(DllName,  CharSet = CharSet.Unicode)]
            static extern bool load_json(string path);

            return load_json(path);
        }

        public static bool SaveJson(string path)
        {
            [DllImport(DllName, CharSet = CharSet.Unicode)]
            static extern bool save_json(string path);

            return save_json(path);
        }


        public static bool ImportXml(string path)
        {
            [DllImport(DllName, CharSet = CharSet.Unicode)]
            static extern bool import_xml(string path);

            return import_xml(path);
        }

        public static bool ExportXlsx(string path)
        {
            [DllImport(DllName, CharSet = CharSet.Unicode)]
            static extern bool export_xlsx(string path);

            return export_xlsx(path);
        }

        public static int GetIndexNum()
        {
            [DllImport(DllName, CharSet = CharSet.Unicode)]
            static extern int get_index_num();

            return get_index_num();
        }

        public static bool GetIndex(ref Index index, bool sort)
        {
            [DllImport(DllName, CharSet = CharSet.Unicode)]
            static extern bool get_index(ref Index.Data data, bool sort);

            var data = index.AllocRecvData();
            
            if (!get_index(ref data, sort))
            {
                return false;
            }

            index.SetData(data);

            Index.FreeData(data);
            return true;
        }

        public static bool GetRecord(string uuid, ref IndexRecord record)
        {
            [DllImport (DllName, CharSet = CharSet.Unicode)]
            static extern bool get_record(string uuid, ref IndexRecord.Data data);

            var data = record.AllocRecvData();

            if (!get_record(uuid, ref data))
            {
                return false;
            }

            record.SetData(data);

            IndexRecord.FreeData(data);
            return true;
        }

        public static void SetDesc(IndexDesc desc)
        {
            [DllImport(DllName, CharSet = CharSet.Unicode)]
            static extern void set_desc(IndexDesc.Data data);

            var data = desc.AllocData();
            set_desc(data);
            IndexDesc.FreeData(data);
        }

        /// <summary>
        /// 新規はUUIDが「""」
        /// </summary>
        /// <param name="record"></param>
        public static void AddAndUpdateRecord(IndexRecord record)
        {
            [DllImport(DllName, CharSet = CharSet.Unicode)]
            static extern void add_and_update_record(IndexRecord.Data data);

            var data = record.AllocSendData();
            add_and_update_record(data);
        }


        public static string GetLibVersion()
        {
            [DllImport("libsakuin.dll", CharSet = CharSet.Unicode)]
            static extern void get_lib_version(StringBuilder sb);

            var sb = new StringBuilder(VersionLength);
            get_lib_version(sb);

            return sb.ToString();
        }

        public static string GetMeCabModelVersion()
        {
            [DllImport("libsakuin.dll", CharSet = CharSet.Unicode)]
            static extern void get_mecab_model_version(StringBuilder sb);

            var sb = new StringBuilder(VersionLength);
            get_mecab_model_version(sb);

            return sb.ToString();
        }

        public static string GetMeCabTaggerVersion()
        {
            [DllImport("libsakuin.dll", CharSet = CharSet.Unicode)]
            static extern void get_mecab_tagger_version(StringBuilder sb);

            var sb = new StringBuilder(VersionLength);
            get_mecab_tagger_version(sb);

            return sb.ToString();
        }

        public static string GetBoostVersion()
        {
            [DllImport("libsakuin.dll", CharSet = CharSet.Unicode)]
            static extern void get_boost_version(StringBuilder sb);

            var sb = new StringBuilder(VersionLength);
            get_boost_version(sb);

            return sb.ToString();
        }

        public static string GetXml2Version()
        {
            [DllImport("libsakuin.dll", CharSet = CharSet.Unicode)]
            static extern void get_xml2_version(StringBuilder sb);

            var sb = new StringBuilder(VersionLength);
            get_xml2_version(sb);

            return sb.ToString();
        }

        public static string GetXlsxWriterVersion()
        {
            [DllImport("libsakuin.dll", CharSet = CharSet.Unicode)]
            static extern void get_xlsx_writer_version(StringBuilder sb);

            var sb = new StringBuilder(VersionLength);
            get_xlsx_writer_version(sb);

            return sb.ToString();
        }
    }
}
