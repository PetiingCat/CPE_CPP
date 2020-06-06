# 所以到底什麼是stringstream?
# 怎麼有istringstream、ostringstream、stringstream，三者有差別嗎？
*以下擷取自zerojudge:(https://zerojudge.tw/ShowProblem?problemid=d098)*  
C++ String Streams 字串串流  
  
String streams 跟 和 函式庫很相近，不同的地方是，string streams 可以讓你在 string 的基礎上使用 I/O，而不是利用串流 stream 當基礎。 函式庫提供和 c 語言裡的 sscanf 和 sprintf 相類似的功能。  
  
在  裡的三個主要類別：  

  *stringstream - 允許輸入輸出  
  *istringstream - 只允許輸入，類似 cin  
  *ostringstream - 只允許輸出，類似 cout  
  
String streams 完全是 iostreams 的從屬類別 subclasses，所以所有在 iostreams 可以使用的函式也都可以用在 stringstream。請看以下網址以便獲得更多 C++ I/O functions 的資訊。  
  
因此，string streams 也支援以下函式：  
  
變數宣告    創造新的 string streams  
 << 和 >>   利用串流運算子來讀取字串串流  
rdbuf()     取得這個 string stream 的緩衝區 buffer 位址  
str()       取得或設定 string streamg 的 string  