#include <iostream>
using namespace std;
int A(int m, int n);
int main()
{
    int x, y;
    while (!cin.eof())  //��LEOF���ɭԴN���� �n���M�N�~���J
    {
        cin >> x >> y;  //��Jm��n�һݭn���Ʀr
        cout << A(x, y) << endl;//��X�̲ת����G
    }
}
int A(int m, int n)
{
    if (m == 0)
    {
        return n + 1;//��m=0���ɭ� ��n+1
    }
    else
    {
        if (n == 0)
        {
            return A(m - 1, 1);//��m!=0���ɭ� n=0���ɭ� recursive �Ө��
        }
        else
        {
            return A(m - 1, A(m, n - 1));//��m!=0,n!=0���ɭ� recursive �Ө��
        }
    }
}