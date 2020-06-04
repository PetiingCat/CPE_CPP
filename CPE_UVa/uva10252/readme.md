**把題目的意思寫成數學描述：Give two strings a and b, find the longest subsequence x with x ∈ (a⋂b) and x is alphabetical order.**  

- **注意題目Output特別提到x可能有很多種請用alphabetical order：**因為整個problem前段都只提到permutation跟sequence，沒有說明到底是哪種排序方式，可是排列順序可以有很多種(遞增、遞減、FIFO、FILO...)會讓人confused，只要X的組成字母大於一種就會存在1個以上的排法，所以這邊是限制請輸出用字母順序排列的x(alphabetical order)  
- **注意有的測資字串是含有空格的**  
