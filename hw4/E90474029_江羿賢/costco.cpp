#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
class LinkedList;                             //for make LinkedList be ListNode's friend
int isFriend(char, char, int, char *, int *); //to check is friend or not

class ListNode
{
private:
    char data;      //the node data
    ListNode *next; //to point to next node
public:
    ListNode() : data(0), next(0){};       //no put value to get a node
    ListNode(char a) : data(a), next(0){}; //put value to get a node
    friend class LinkedList;               //declare the friend
};

class LinkedList
{
private:
    ListNode *first; // first node
public:
    LinkedList() : first(0){};
    void Push_back(char a) //push the node at back
    {
        ListNode *newNode = new ListNode(a); //new a node to push back

        if (first == 0) //if it's empty inside,make first to point the newnode
        {
            first = newNode;
            return;
        }

        ListNode *current = first; //if it's not empty inside to declare a current to travesal
        while (current->next != 0)
        {
            current = current->next;
        }
        current->next = newNode; // after travesal end,put the new node at back of current
    }
    void Push_front(char a)
    {
        ListNode *newNode = new ListNode(a); // new the node
        newNode->next = first;               // put the first on the next of new node
        first = newNode;                     // make first point to new node
    }
    void enqueue(char input, int group, char *costom, int *site) //do enqueue
    {
        ListNode *current = first;               //make current point to first
        ListNode *before = first;                //make before point to first
        ListNode *newNode = new ListNode(input); //new a node
        if (first == 0)                          //if no node inside
        {
            Push_back(input); //push the node at back
            return;
        }
        while (current != 0) //travesal the linked list
        {
            if (isFriend(input, current->data, group, costom, site))
            {
                if (current == first) //if friend is at first
                {
                    Push_front(input); //put the node at front of linked list
                    return;
                }
                else //if friend is not at first
                {
                    before->next = newNode;  //make before's next be new node
                    newNode->next = current; //new node's next it's friend
                    return;
                }
            }
            before = current;        //go to next to search friend
            current = current->next; //go to next to search friend
        }
        Push_back(input); //if no friend inside,push the node at the back of linked list
    }
    void dequeue() //take out the first node and see take out what
    {
        if (first == 0) //if no node inside , print is Empty
        {
            cout << "is Empty" << endl;
        }
        else
        {
            char thechar;            //use it to store the first data
            thechar = first->data;   //store it
            ListNode *temp = first;  //use temp to point the first
            first = first->next;     //first go to point next
            delete temp;             //delete the origin first
            temp = 0;                //make temp to point null
            cout << thechar << endl; //print the origin first data
        }
    }
};

int main()
{
    //put the data in
    int group = 0;        //to store number of group
    int numofpeople = 0;  //to store number of people in group
    char thechar = 0;     //to store the char input in temp
    char costom[30] = {}; //to store name of the costomer
    int site[30] = {};    //to store number of people in each group
    int count = 0;        //to make it go to next in array

    cin >> group;                   // enter how many group
    for (int i = 0; i < group; i++) //store each group's data
    {
        cin >> numofpeople;    // enter how many people
        site[i] = numofpeople; // to store number of people int each group

        while (cin.get(thechar))
        {
            if (thechar - '0' == -38) //if input enter then the input over
            {
                break;
            }
            if (thechar - '0' != -16) //if not input space put input in
            {
                costom[count] = thechar; //store the name
                count++;                 //go to next in array
            }
        }
    }
    //put the data over

    LinkedList list;
    char enorde[10] = {};    // to see input enqueue or dequeue
    char input = 0;          // to store the input
    char en[10] = "ENQUEUE"; //enqueue's string
    char de[10] = "DEQUEUE"; //dequeue's string

    while (cin.peek() != EOF) //would do it until EOF
    {
        cin >> enorde;
        if (!strcmp(enorde, en)) //if enter ENQUEUE
        {
            cin >> input;                             //the buffer would put in
            list.enqueue(input, group, costom, site); //do enqueue
        }
        if (!strcmp(enorde, de)) //if enter DEQUEUE
        {
            setbuf(stdin, NULL); //flush the buffer
            list.dequeue();      //do dequeue
        }
        setbuf(stdin, NULL); //flush the buffer
    }
}
int isFriend(char input, char inside, int group, char *costom, int *site) //is friend or not
{
    int i; // to see the site of input in costom
    for (i = 0; i < 30; i++)
    {
        if (input == costom[i]) //find it and break
            break;
    }
    int ingroup;                                  // to check which group the input in
    int toseepeople = 0;                          //to check how many people before input's group
    for (ingroup = 0; ingroup < group; ingroup++) //do how many group's time
    {
        if (toseepeople <= i && i < toseepeople + site[ingroup]) //to check the range of the input
        {
            for (int j = toseepeople; j < toseepeople + site[ingroup]; j++) //to search the people is input's friend
            {
                if (costom[j] == inside) //if find it return 1
                {
                    return 1;
                }
            }
            break; //if not input's friend and return 0
        }
        toseepeople += site[ingroup]; //to search next group
    }
    return 0;
}
