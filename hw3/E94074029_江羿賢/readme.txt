hw3.cpp
先觀察這個問題，要使用到queue這個資料結構的技巧
queue裡面包含了enqueue跟dequeue，而在enqueue當中要先確認有沒有朋友在裡面，所以把這個動作另外寫成isFriend
這個等最後再說，
先講主程式的整個架構

queue的設定
想要有一個環狀的queue
依據人數先設定一個適當的容量(capacity)30給queue，並使得queue為存char類型的陣列
宣告front跟rear在0的位置，作為一個環狀queue的設置

輸入資料的處理
要把獲得的資料存成方便拿取的資料，利用group把組數存起來，
以及用costom這個array把人的名字依照順序存起來，並且用site這個array把每組的人數存起來，
才能知道存在costom的這些人誰跟誰是朋友
先輸入每組的人數numberofpeople並存進site裡面
宣告一個位置count跟暫存用的thechar，並利用while(cin.get(thechar))用這個方式來依序把人存入costom中，並利用count++來換格子
這樣就把group(組數),costom(人名),site(各組的人數)都存取起來了。

enqueue跟dequeue的輸入
宣告一個陣列enorde來儲存所想要的動作，跟一個input來存enqueue所想要的輸入
並設定好兩個陣列為 en 跟 de 分別存入要進入的關鍵字 ENQUEUE 跟 DEQUEUE
處理好之後利用 while(!cin.eof())來使得當遇到EOF可以結束程式的運行
接著可以輸入想輸入的字
並在裡面利用strcmp來比對enorde是跟 en 一樣還是跟de一樣來判斷要執行哪件事情
如果要enqueue的話 利用buffer還存著的值把input輸入進去，並且呼叫enqueue來完成enqueue這個動作
如果要dequeue的話 利用setbuf(stdin, NULL)把buffer清乾淨，避免不必要的麻煩，並且呼叫dequeue來完成dequeue的動作
最後執行一次setbuf(stdin, NULL)來避免還有殘留的東西

主要的架構就大概解釋到這裡，接下來來解釋 enqueue dequeue 跟 isFriend 這三個function的實現

1. enqueue
首先利用front == (rear + 1) % capacity來判斷有沒有滿，如果滿的話就輸出is Full,invalid input
如果沒有滿的話就enqueue進去
先宣告一個check當他找到朋友就++當作一個true跟false的工具
宣告position來儲存朋友的位置
宣告last先存rear，跟before設定為last的前一個，以便於之後的交換
利用 for (position = (front + 1) % capacity; position != (rear + 1) % capacity; position = (position + 1) % capacity)
就可以順利的把從front的後面一格到rear都檢查一次，並利用isFriend檢查有沒有朋友在裡面，如果有就讓check++並跳出迴圈
藉由這樣也得到了position就是朋友的位置
接下來利用check看有沒有朋友，如果有的話把rear往後一格來使得多一個有位置放，
並先初始話last為rear，把before設在rear的前一個，而這邊要注意的是rear如果是0的話，他的前一個就要是那個array的最後一個
也就是capacity-1，利用ifelse來完成
利用while(last != position)這個迴圈的條件，讓他朋友之後的人全部都往後一格，直到他朋友也移動完
利用queue[last] = queue[before]來把前面的存到後面的，之後把last跟before一起往前繼續移動其他人，
移動完後，利用queue[position] = input把要插隊的人插進他朋友原本的位置
如果他沒有朋友在隊伍裡面的話，就單純的把rear往後移一格，之後排進去rear即可

2. dequeue
這邊我的dequeue不回傳值，而是利用cout直接在function內印出我dequeue了甚麼東西
首先先利用if (front == rear)來判斷是不是空的
空的話就印出is Empty,can't dequeue
不是空的話就把front往前移一格，並印出queue[front]來得知dequeue了甚麼

3. isFriend
要比對輸入的人是不是有朋友的function，要有幾項資料
要有比對者是不是他朋友的inside跟組的數量group以及人的名單costom和他們每組的人數site
資料都有了先宣告一個i來找輸入者是在costom的第幾個位置，利用for從0號開始找到capacity-1號
找到後break而i就有了輸入者在costom是幾號了
有了輸入者在哪裡後，先宣告一個ingroup來存現在是第幾組的
跟toseepeople來存在costom中有前面的號碼是找過的
利用for (ingroup = 0; ingroup < group; ingroup++)來把每一組都找過
並在最後用toseepeople += site[ingroup]存找過的人
並在裡面看i是不是有在toseepeople<=i<toseepeople+site[ingroup]
來看是不是該組的，如果不是就往下一組找，
如果是的話讓迴圈從toseepeople跑到toseepeople+site[ingroup]
看看costom的這個區間內有沒有等同於inside的，如果有的話就return 1
如果inside找完都沒有的話就跳出組別的迴圈return 0
就可以實現isFriend並回傳1或0給enqueue使enqueue能判斷有沒有朋友了
