內含有solitaire.cpp跟costco.cpp的readme以及個別的Bonus

solitaire.cpp

這個程式主是要把卡先洗牌後再來一個一個依序的找，而分成兩種，有找到跟沒找到

	------找到 K ! 把第一張拿走，其他依序補上------找 Q
雜亂的牌                                                                以此類推直到找完
	------沒找到 K ! 把第一張牌放到最後，其他依序補上------繼續找 K

所以動作有以下:洗牌,把第一張放到最後,把第一張拿走,顯示出現在牌的順序 一共四個動作

資料型態:先用兩個char的陣列來存這十三張牌的順序跟洗牌，而10就先利用T代替，等到要輸出時在來判斷就好，
可以省下一些心力去處理二維陣列的問題。洗完牌後，按照洗完後的順序，依序放進Linked List裡面，就可以方便的執行
把第一張放到最後,把第一張拿走,顯示出現在牌的順序等動作。
而LinkedList中利用first來指著第一個，Node裡面儲存著資料，並指著下一個是哪。

主要的執行方式:
先把兩個陣列宣告好，一個是存正確順序的，一個是用來洗牌的。
先把牌洗好後，把打亂的順序的放入Linked List當中，利用for迴圈來找K~A。
一樣->先秀出目前的牌，並且印出是哪個要被抽出了，之後抽牌，並把尋找的引索i++找下一張牌
不一樣->先秀出目前的牌，然後把第一張放到最後一張

動作的實現:

1.洗牌 shuffle
把card傳入函式中，並把srand設定成time(NULL)，來獲得每次都能隨機取得
並宣告一個暫存的char temp跟一個之後會被隨機生成的random
之後用for迴圈從第一張開始換到最後一張，random為0~12的隨機數字
從第一張開始跟被第random的號碼交換，直到13張都交換過一次才停
而交換是類似於swap，先把原本存到temp再把被換的那號跟random那號換，
並把random那號設成temp，也就是原本的那號，這樣子就能夠實現洗牌了，
之後再利用for迴圈把這個洗牌順序Push_back回去，
而Push_back 是先傳入一個char，利用newNode指著他，如果first為0也就是空的Linked List的話，就把first指向newNode
如果不是空的話，利用while (current->next != 0)來做travesal，直到最後一個指向NULL時，改成指向newNode，
這樣就完成Push_back了。

2.秀出 PrintList
先看first是否指向0，如果是0的話，代表這個是空的LinkedList，印出Empty的字樣
如果不是的話就宣告一個current指標來移動位置，從first移動到current==0，而這邊要注意的是
在前面已經把10設成T了，所以在這邊要先檢查將要印出來的是否為T，如果不是就照常印出原本的卡(current->data)，
如果是T的話，就印出10，這樣就完成PrintList的動作了。

3.抽起來 takeout
用一個temp指向first，避免不見，把first移動到下一個，再利用temp把原本的刪除，就可以輕鬆的把第一張牌拿起來了

4.把第一張放到最後 takeoutwhat+Push_back
這個動作可以拆解成兩個前面做過的動作，也就是把第一張先抽起來，再放進最後的地方。
這裡所需要調整的是takeout，再重新寫一個可以return takeout甚麼的function，也就是所謂的takeoutwhat，而跟takeout不同於，
有利用一個char thechar把原本第一張牌的號碼記下來，拿起來之後，利用return回傳那張牌的字，再利用Push_back放進最後面

Bonus:
這次solitaire.cpp是利用一個新學習到的資料結構LinkedList所完成，而其中也省了不少麻煩在處理移動卡牌的問題。
比較主要的差異是在於抽起來(takeout)跟把第一張放到最後(takeoutwhat+Push_back)。
其中在使用array的處理中，必須要利用一個數字來記住現在有幾張牌，才能精準的使用for迴圈來做相對應的動作。
而使用LinkedList的話，就省去了這個步驟，只要指到最後一個
是指向0的話就知道沒有了，也可以藉由first是否==0知道LinkedList是不是空的。
而在抽起來(takeout)的動作中，使用array來takeout第一個的話是非常麻煩且浪費時間，因為把第一個拿出來後
就勢必把後面的每一個都往前面一格。而使用LinkedList的話，可以的把first指到下一個，並把原本的刪除掉就好了，有
比較好的變動性來拿第一個資料。
而在把第一張放到最後(takeoutwhat+Push_back)的動作，在array的也是要把第一個拿出來，並且把後面每一個往前放一格
，而在LinkedList中只要把第一張拿起來，並把他記起來，並把他放到最後面就好，而這邊的把它放到最後面的動作，在array
只要看清楚位置存就好，而LinkedList要先從第一個走到最後一個才能放新的Node。

costco.cpp

先觀察這個問題，要使用到使用LinkedList來構成queue的技巧
queue裡面包含了enqueue跟dequeue，而在enqueue當中要先確認有沒有朋友在裡面，所以把這個動作另外寫成isFriend
先講主程式的整個架構
而LinkedList中利用first來指著第一個，Node裡面儲存著資料，並指著下一個是哪。

queue的設定
用LinkedList把資料有序的排起來，裡面主要功能有dequeue跟enqueue來操作這個queue
利用first來知道頭在哪裡

輸入資料的處理
要把獲得的資料存成方便拿取的資料，利用group把組數存起來，
以及用costom這個array把人的名字依照順序存起來，並且用site這個array把每組的人數存起來，
才能知道存在costom的這些人誰跟誰是朋友
先輸入每組的人數numberofpeople並存進site裡面
宣告一個位置count跟暫存用的thechar，並利用while(cin.get(thechar))用這個方式來依序把人存入costom中，
並利用count++來換格子，這樣就把group(組數),costom(人名),site(各組的人數)都存取起來了。

enqueue跟dequeue的輸入
宣告一個陣列enorde來儲存所想要的動作，跟一個input來存enqueue所想要的輸入
並設定好兩個陣列為 en 跟 de 分別存入要進入的關鍵字 ENQUEUE 跟 DEQUEUE
處理好之後利用cin.peek來使得當遇到EOF可以結束程式的運行
接著可以輸入想輸入的字
並在裡面利用strcmp來比對enorde是跟 en 一樣還是跟de一樣來判斷要執行哪件事情
如果要enqueue的話 利用buffer還存著的值把input輸入進去，並且呼叫enqueue來完成enqueue這個動作
如果要dequeue的話 利用setbuf(stdin, NULL)把buffer清乾淨，避免不必要的麻煩，並且呼叫dequeue來完成dequeue的動作
最後執行一次setbuf(stdin, NULL)來避免還有殘留的東西

主要輸入的架構就大概解釋到這裡，接下來來解釋 enqueue dequeue 跟 isFriend 這三個function
1. enqueue
而enqueue中也有著其他三個動作，插在最前面(Push_front)，插在最後面(Push_back)，以及插在中間
插在最前面(Push_front)
先建立一個node並用newNode指著，並把newNode的下一個指著原本的irst，在把first更新成newNode就完成了
插在最後面(Push_back)
而Push_back 是先傳入一個char，利用newNode指著他，如果first為0也就是空的Linked List的話，就把first指向newNode
如果不是空的話，利用while (current->next != 0)來做travesal，直到最後一個指向NULL時，改成指向newNode，
這樣就完成Push_back了。
最後是插在中間的動作，這個跟整個enqueue一起講
首先是要有兩個指標可以指著一個前面一個後面，
宣告current跟before來一個作為現在的位置，一個作為上一個位置，跟宣告一個newNode指向由input新生成的Node，
這樣就把工具都準備好了，可以開始來判斷情況了
首先先檢查是不是空的LinkedList，如果是的話，就直接Push_back就好了。
如果LinkedList是有東西的話，利用while (current != 0)來travesal整個LinkedList，並把before跟current往前繼續移動
來找找看有沒有input的朋友，
如果遇到朋友在隊伍裡的話，先看看朋友是不是在隊伍的第一個，如果是的話，利用Push_front，把input放到最前面
如果遇到的朋友不是在第一個的話，讓上一個人(before)的next變成newNode，把newNode的next指到他的朋友，這樣就完成插隊了
如果都travesal完了都沒有遇到朋友，很可惜的，就只能讓他Push_back在最後面了

2. dequeue
首先先判斷first是否為0，如果是0的話表示裡面是空的，印出is Empty，
如果不是空的話利用一個thechar去儲存將被刪去的第一個資料，並用一個temp指著原本的first，以免不見
再來將first往後移一格，讓他到他的next去，並把第一個資料delete掉，之後把原本那裡面的資料印出來，
就完成了dequeue

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

Bonus:
這次的costco作業，從原本的環狀queue，改成了LinkedList的queue，
最主要的改變在於enqueue跟dequeue這兩個的處理方式，
先來說enqueue，本來的環狀的enqueue是利用一個front跟一個rear來記住他們在array的甚麼位置，利用rear往後移動
並指派一個值，而比較麻煩的是還要看是不是繞一圈的判斷，要利用if-else跟%來判斷，而且空間也是寫好的，太小的話
會有滿的危機，而LinkedList的寫法是利用動態配置，並利用一個接著一個，手拉著手的寫法，這樣比較沒有繞圈的問題，
也可以一直排隊，當然不要太誇張就可以排得進去，而LinkedList在插隊時需要判斷他朋友的位置是否在第一個而做出不同的插隊
實作方式，而利用array做的麻煩處是在於它插進去的話，只要在後面的都必須往後一格讓出位置給新插入的，LinkedList只要接起來
就好，更動朋友前一個人的next，並把自己指向朋友就可以完成了，而找朋友的方式兩個都是從頭開始找看看有沒有朋友，
一個是利用array的號碼，一個是利用一個接著一個的找。
再來是dequeue的部分，array實作是先檢查front有沒有==rear，空的話就不能dequeue，不是空的話
用front往前走來做dequeue，而LinkedList是把先把要dequeue的資料先存起來，並把first往下走，把原本的刪掉，
這邊的觀念就比較相同，利用可以代表頭的一個表示型態，往前走，而front比較像是有標號的概念，而first是確實的
指向資料。
	



