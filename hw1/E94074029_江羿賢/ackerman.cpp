#include <iostream>
using namespace std;
int A(int m, int n);
int main()
{
    int x, y;
    while (!cin.eof())  //當他EOF的時候就停止 要不然就繼續輸入
    {
        cin >> x >> y;  //輸入m跟n所需要的數字
        cout << A(x, y) << endl;//輸出最終的結果
    }
}
int A(int m, int n)
{
    if (m == 0)
    {
        return n + 1;//當m=0的時候 為n+1
    }
    else
    {
        if (n == 0)
        {
            return A(m - 1, 1);//當m!=0的時候 n=0的時候 recursive 該函數
        }
        else
        {
            return A(m - 1, A(m, n - 1));//當m!=0,n!=0的時候 recursive 該函數
        }
    }
}