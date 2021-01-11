#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    //initialize
    int before[200] = {};   //the before vertex
    int after[200] = {};    //the after vertex
    int weight[200] = {};   //the weight of vertex
    int ee[200] = {};       //the ee
    int le[200] = {};       //the le
    int e[200] = {};        //the e
    int l[200] = {};        //the l
    int slack[200] = {};    //the slack
    int critical[200] = {}; //the critical or not
    int path[200] = {};     //the path
    int countpath = 0;      //to count path
    int time = 0;           //how many activity
    int activity = 0;       //the number of activity
    int be = 0;             //before temp
    int af = 0;             //after temp
    int w = 0;              //weight temp
    int finish = 0;         //the finish vertex
    for (int i = 0; i < 200; i++)
        le[i] = 999; //initialize the le to 999
    //initialize end

    //input data
    cin >> time; //input how many time
    while (time--)
    {
        cin >> activity >> be >> af >> w;
        before[activity] = be; //input before
        after[activity] = af;  //input after
        weight[activity] = w;  //input weight
    }
    //input data end

    //do ee
    for (int i = 1; i <= activity; i++)
    {
        if (ee[after[i]] < ee[before[i]] + weight[i]) //to count the ee and push in
            ee[after[i]] = ee[before[i]] + weight[i];
    }
    finish = after[activity]; //set the finish event
    //do ee end

    //do le
    le[finish] = ee[finish]; //take the finish vertex ee value put to le
    for (int i = activity; i >= 1; i--)
    {
        if (le[before[i]] > le[after[i]] - weight[i]) //to count the le and push in
            le[before[i]] = le[after[i]] - weight[i];
    }
    //do le end

    //do e
    for (int i = 1; i <= activity; i++)
    {
        e[i] = ee[before[i]]; //to count the e and push in
    }
    //do e end

    //do l
    for (int i = activity; i >= 1; i--)
    {
        l[i] = le[after[i]] - weight[i]; //to count the l and push in
    }
    //do l end

    //do slack,critical,path
    for (int i = 1; i <= activity; i++)
    {
        slack[i] = l[i] - e[i]; //to count the slack
        if (!slack[i])          //to check it's critical or not
        {
            critical[i] = 1;       //set critical 1
            path[countpath++] = i; //push to the path
        }
        else
            critical[i] = 0; //set critical 0
    }
    //do slack,critical,path end

    //print event table
    cout << left;
    cout << setw(7) << "event" << setw(7) << "ee" << setw(7) << "le" << endl;
    for (int i = 0; i <= finish; i++)
        cout << setw(7) << i << setw(7) << ee[i] << setw(7) << le[i] << endl;
    cout << endl;
    //print event table end

    //print act. table
    cout << setw(7) << "act." << setw(7) << "e" << setw(7) << "l" << setw(7) << "slack" << setw(7) << "critical" << endl;
    for (int i = 1; i <= activity; i++)
        if (critical[i]) //to see it's critical or not
            cout << setw(7) << i << setw(7) << e[i] << setw(7) << l[i] << setw(7) << slack[i] << setw(7) << "YES" << endl;
        else
            cout << setw(7) << i << setw(7) << e[i] << setw(7) << l[i] << setw(7) << slack[i] << setw(7) << "NO" << endl;
    cout << endl;
    //print act. table end

    //print path
    for (int i = 0; i < countpath; i++)
        cout << path[i] << " ";
    //print path end
}