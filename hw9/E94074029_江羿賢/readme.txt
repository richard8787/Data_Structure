aoe.cpp

資料存放:
AOE中會輸入的值利用before,after跟weight來存分別三個值，而利用他們的
activity作為index來尋找跟存取，而在table所需要的數據分別為
ee,le,e,l,slack,critical,path，分別給定適當大小的矩陣來存，
而其中所需要注意的是，因為le需要用到比小，所以先初始化很大的值給他
在變數中利用be,af,w來作為暫時存放輸入的值，比較容易讀，並建立一個finish
來存finish vertex是幾號

輸入:
利用time來看會輸入幾次，並利用while(time--)來，並讀取相對應的數值
before,after,weight

主要運行內容:
先計算ee及le之後，在去做其他的計算會方便很多

ee:從第一個開始讀取到最後一個，比較after的ee值跟before的ee值
+weight，如果後者比較大的話就將數據更新成後者。

le:le跟ee也是相近的觀念，只不過需要從最後面開始更新，而需要注意的是，
le的finish vertex的值會跟ee的finish vertex的值一樣，所以先更新這個值
之後比較le的before跟他的after的值-weight，如果後面的值較小就更新那個值

e:有了ee之後就很簡單了，從第一個開始讀取到最後，每個e都存他before的ee值即可

l:有了le之後也很簡單，雖然可以從第一個讀，可是我是從往後讀回來比較有相對應的感覺，
每個l就存他after的值-他的weight即可

slack:從第一個到最後一個，把l的值減去e的值即可得到

critical:看slack，如果是0的話就設成1，其他就設成0

path:而路徑的部分看他的critical如果是1的話就添加進去

輸出:
print出三個，event table,act. table,path，需要注意的是利用
cout<<left跟setw的指令

event table:從vetex 0讀到vertex finish，print出ee跟le

act. table:從第一個讀到最後，print出e,l,slack,critical

path:從第一個讀到最後，print出path
