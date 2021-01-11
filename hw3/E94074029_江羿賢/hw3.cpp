#include <cmath>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define capacity 30   //the capacity of queue
char queue[capacity]; // the queue to put the char
int front = 0;        //queue's front
int rear = 0;         //queue's rear

void enqueue(char, int, char *, int *);       //enqueue the data
void dequeue();                               //dequeue the data by cout,so using void
int isFriend(char, char, int, char *, int *); //to check is friend or not

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

    char enorde[10] = {};    // to see input enqueue or dequeue
    char input = 0;          // to store the input
    char en[10] = "ENQUEUE"; //enqueue's string
    char de[10] = "DEQUEUE"; //dequeue's string

    while (!cin.eof()) //would do it until EOF
    {
        cin >> enorde;
        if (!strcmp(enorde, en)) //if enter ENQUEUE
        {
            cin >> input;                        //the buffer would put in
            enqueue(input, group, costom, site); //do enqueue
        }
        if (!strcmp(enorde, de)) //if enter DEQUEUE
        {
            setbuf(stdin, NULL); //flush the buffer
            dequeue();           //do dequeue
        }
        setbuf(stdin, NULL); //flush the buffer
    }
}
void enqueue(char input, int group, char *costom, int *site)
{
    if (front == (rear + 1) % capacity) //to check full or not
    {
        cout << "is Full,invalid input" << endl; //print is full
    }
    else
    {
        int check = 0;                                                                                                   //to check have friend inside or not
        int position = 0;                                                                                                //to store the position of input's friend
        int last = 0;                                                                                                    //to store the rear of the queue
        int before = 0;                                                                                                  //to store before of the last
        for (position = (front + 1) % capacity; position != (rear + 1) % capacity; position = (position + 1) % capacity) //search people inqueue
        {
            if (isFriend(input, queue[position], group, costom, site)) //to see whether friend in the inside
            {
                check++; //if find it make check to 1
                break;   //found the friend so break out the for
            }
        }
        if (check) //check have friend or not
        {
            rear = (rear + 1) % capacity; //make rear move
            last = rear;                  //make last go to rear
            if (last)                     //check the last
            {
                before = last - 1; //if not zero , to do -1 then put into the before
            }
            else
            {
                before = capacity - 1; //if zero , before go to end of array
            }
            while (last != position) //until move done
            {
                queue[last] = queue[before]; //all people after input's friend go back
                last = before;               //make last move until visit input's friend
                if (last)
                {
                    before = last - 1; //if not zero , to do -1 then put into the before
                }
                else
                {
                    before = capacity - 1; //if zero , before go to end of array
                }
            }
            queue[position] = input; //input to go it's friend's site
        }
        else // no friend
        {
            rear = (rear + 1) % capacity; //rear move
            queue[rear] = input;          //put the input in the rear
        }
    }
}
void dequeue()
{
    if (front == rear) //check whether empty or not
    {
        cout << "is Empty,can't dequeue" << endl; //is empty
    }
    else
    {
        front = (front + 1) % capacity; //front move
        cout << queue[front] << endl;   //print the dequeue's result
    }
}
int isFriend(char input, char inside, int group, char *costom, int *site) //is friend or not
{
    int i; // to see the site of input in costom
    for (i = 0; i < capacity; i++)
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
