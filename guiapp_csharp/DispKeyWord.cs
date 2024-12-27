namespace SakuinKun
{
    /// <summary>
    /// 表示用キーワード
    /// </summary>
    public class DispKeyWord
    {
        /// <summary>
        /// メインキーワード
        /// </summary>
        public string MainKey { get; set; } = string.Empty;
        /// <summary>
        /// メインキーワード読み
        /// </summary>
        public string MainYomi { get; set; } = string.Empty;

        /// <summary>
        /// サブキーワード
        /// </summary>
        public string SubKey { get; set; } = string.Empty;
        /// <summary>
        /// サブキーワード読み
        /// </summary>
        public string SubYomi { get; set; } = string.Empty;

        /// <summary>
        /// ノンブル
        /// </summary>
        public string Nombre { get; set; } = string.Empty;

        /// <summary>
        /// UUID（デフォルトでは非表示）
        /// </summary>
        public string UUID { get; set; } = string.Empty;
    }
}
