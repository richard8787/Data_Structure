#include <iostream>
#include <string>
using namespace std;
void powerset(char[][10], int, string);
int main()
{
    char thechar; //宣告一個能夠檢驗是否為enter或space的char
start:
    int i = 0; //把二維陣列的號碼歸0
    int j = 0;
    char a[10][10] = {}; //宣告一個10*10的二維陣列 並把其清空
    while (cin.get(thechar))
    {
        if (thechar - '0' == -38) //看有沒有遇到enter,有的話結束迴圈,並顯示結果
        {
            break;
        }
        if (thechar - '0' == -16) //看有沒有遇到space,有的話換下一列,並把行重新回到0
        {
            i++;
            j = 0;
        }
        a[i][j] = thechar; //把輸入的字存進去
        j++;               //往下一行
    }
    cout << endl; //換行
    powerset(a, 0, "");
    cout << endl;//換行
    if (cin.peek() != EOF) //當沒有EOF的時候 重新執行程式
    {
        goto start;
    }
    return 0;
}
void powerset(char a[][10], int i, string thestring)
{
    int numberofstring = 0;
    for (numberofstring = 0; numberofstring < 10; numberofstring++) //看看有幾組字串
    {
        if (a[numberofstring][0] == NULL)
        {
            break; //一找到就跳出迴圈
        }
    }

    if (i == numberofstring)//當選擇選完的時候就輸出 並return
    {
        cout << "{" << thestring << "}"<< " ";
        return;
    }
    powerset(a, i + 1, thestring);//往下一個字串，並不選第i字串的情況
    powerset(a, i + 1, thestring + a[i]);//往下一個字串，把第i個字串選起來的情況
    
}
