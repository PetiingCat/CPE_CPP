## uva10041 Vito's Family  
Key: 在一條街道上拜訪附近親友，將地址**排序**後從**中位數**地址訪問其他地址的總距離會是最短距離，計算距離用**絕對值函數**。
C++ Skill:
- sort(); 需要include <algorithm> 
- sort可以自訂排序，需要額外撰寫 bool cmp(){}，sort(arr, arr+n, cmp); 
- abs(); 取絕對值 需要include <algorithm>
