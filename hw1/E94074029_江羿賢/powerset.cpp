#include <iostream>
#include <string>
using namespace std;
void powerset(char[][10], int, string);
int main()
{
    char thechar; //�ŧi�@�ӯ������O�_��enter��space��char
start:
    int i = 0; //��G���}�C�����X�k0
    int j = 0;
    char a[10][10] = {}; //�ŧi�@��10*10���G���}�C �ç��M��
    while (cin.get(thechar))
    {
        if (thechar - '0' == -38) //�ݦ��S���J��enter,�����ܵ����j��,����ܵ��G
        {
            break;
        }
        if (thechar - '0' == -16) //�ݦ��S���J��space,�����ܴ��U�@�C,�ç�歫�s�^��0
        {
            i++;
            j = 0;
        }
        a[i][j] = thechar; //���J���r�s�i�h
        j++;               //���U�@��
    }
    cout << endl; //����
    powerset(a, 0, "");
    cout << endl;//����
    if (cin.peek() != EOF) //��S��EOF���ɭ� ���s����{��
    {
        goto start;
    }
    return 0;
}
void powerset(char a[][10], int i, string thestring)
{
    int numberofstring = 0;
    for (numberofstring = 0; numberofstring < 10; numberofstring++) //�ݬݦ��X�զr��
    {
        if (a[numberofstring][0] == NULL)
        {
            break; //�@���N���X�j��
        }
    }

    if (i == numberofstring)//���ܿ粒���ɭԴN��X ��return
    {
        cout << "{" << thestring << "}"<< " ";
        return;
    }
    powerset(a, i + 1, thestring);//���U�@�Ӧr��A�ä����i�r�ꪺ���p
    powerset(a, i + 1, thestring + a[i]);//���U�@�Ӧr��A���i�Ӧr���_�Ӫ����p
    
}
