You will be given N numbers and a positive integer M.  
1.  依modulo(模, 取餘數)作ascending(升序)排列，即 n%M **餘數值越大排越後面**    
2.  **If** there is a tie(平手, 平局, 相等) between an **odd number** and an **even number** (that is their modulo M value is the same)  
    **then** the **odd number** will precede(優先, 前於) the even number.  
3.  **If** there is a tie between **two odd numbers** (that is their modulo M value is the same)  
    **then** **the larger odd number** will precede the smaller odd number.  
4.  **if** there is a tie between **two even numbers** (that is their modulo M value is the same)  
    **then** **the smaller even number** will precede the larger even number.  
5.  For remainder value of **negative numbers** follow the rule of C programming language: 
    **A negative number can never have modulus greater than zero.** E.g. -100 MOD 3 = -1, -100 MOD 4 = 0, etc.  