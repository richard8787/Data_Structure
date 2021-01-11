#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int a[101];                     //store tree
int collapsingFind(int i);      //find and collapse
void heightUnion(int i, int j); //union two tree
int main()
{
    int trees;    //the number of tree
    int nodes;    //the number of node
    int index;    //the node's index
    int parent;   //the node's parent
    cin >> trees; //input number of tree
    while (trees--)
    {
        cin >> nodes; //input number of node
        while (nodes--)
        {
            cin >> index >> parent; //input node's index and parent
            a[index] = parent;      //make the node to point it's parent
        }
    }
    int tofind;              //the node wanted to find
    int u1, u2;              //the tree wanted to union
    vector<int> output;      //to store the output
    char choose[6];          //choose what to do
    char Stop[6] = "STOP";   //the stop
    char Find[6] = "FIND";   //the find
    char Union[6] = "UNION"; //the union
    while (1)
    {
        cin >> choose;             //input the choose
        if (!strcmp(choose, Find)) //do find
        {
            cin >> tofind;                            //input to find
            output.push_back(collapsingFind(tofind)); //store the output
        }
        if (!strcmp(choose, Union)) //do union
        {
            cin >> u1 >> u2;     //input wanted to union
            heightUnion(u1, u2); //do union
        }

        if (!strcmp(choose, Stop)) //do stop
        {
            for (int i = 0; i < output.size(); i++)
                cout << output[i] << endl; //print all output
            break;                         //end
        }
    }
}
int collapsingFind(int i)
{
    int root, trail, lead;
    int count = 0; //the moves
    for (root = i; a[root] >= 0; root = a[root])
        count++; //links traversed
    for (trail = i; trail != root; trail = lead)
    {
        if (root == a[trail]) //to make it not perform an extra link reset
            break;
        lead = a[trail];
        a[trail] = root; //make the node point to the root
        count++;         //link reset
    }
    return count; //return the moves
}
void heightUnion(int i, int j)
{
    if (a[i] > a[j]) //check the tree height,make j be root
        a[i] = j;
    else
    {
        if (a[i] == a[j]) //if tree height is the same,tree height would +1
            a[i]--;
        a[j] = i; //check the tree height,make j be root
    }
}