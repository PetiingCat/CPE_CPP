# 本題的關鍵其實不是演算法而是標準鍵盤的順序  
# 題目所稱的標準鍵盤其實是IBM鍵盤序：" `1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./"  
  
<<流程>>  
1.  輸入待解碼的Input_string  
2.  建立鍵盤標準輸入陣列__keybord  
3.  for i = 0 to i < Input_string.length : 線性檢查Input_string進行解碼  
4.      if Input_string[i]是空格:   
5.      直接輸出空格(by 觀察題目的側資，空格不用解碼)  
6.  else: (不是空格)  
7.      Input_string[i]大寫字母轉小寫  
8.      查詢Input_string[i]在keybord裡的位置  
9.      輸出該鍵位置-2的鍵值  
10. endif  
11. endfor  

<<分析>>
第8步驟「查詢Input_string[i]在keybord裡的位置」  
一般的方法是使用線性查找，則每次對Input_string[i]解碼時都要花費keybord.length的時間  
因此，我改使用Hash table將查找的時間降為O(1)  