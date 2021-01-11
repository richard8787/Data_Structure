#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
class LinkedList; //for make LinkedList be ListNode's friend

class ListNode //the node
{
private:
    char data;      //the node data
    ListNode *next; //to point to next node
public:
    ListNode() : data(0), next(0){};       //no put value to get a node
    ListNode(char a) : data(a), next(0){}; //put value to get a node
    friend class LinkedList;               //declare the friend
};

class LinkedList //the linked list
{
private:
    ListNode *first; // the first node
public:
    LinkedList() : first(0){}; //build the linked list
    char getfirst()
    {
        return first->data; //to get the first node's data
    }
    void PrintList() //print the whole linked list in order
    {
        if (first == 0) //if no node inside print Empty
        {
            cout << "Empty";
            return;
        }
        ListNode *current = first; //declare a pointer current to travesal
        while (current != 0)       //until travesal over
        {
            if (current->data != 'T')         //if the data not T
                cout << current->data << " "; //print origin data
            else
                cout << "10 ";       // if the data is T,print 10
            current = current->next; // go to next node
        }
        cout << endl;
    }
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
    void takeout() //take out the first node
    {
        ListNode *temp = first; //use temp to point the first
        first = first->next;    //first go to point next
        delete temp;            //delete the origin first
        temp = 0;               //make temp to point null
    }
    char takeoutwhat() //take out the first node and see take out what
    {
        char thechar;           //use it to store the first data
        thechar = first->data;  //store it
        ListNode *temp = first; //use temp to point the first
        first = first->next;    //first go to point next
        delete temp;            //delete the origin first
        temp = 0;               //make temp to point null
        return thechar;         //return the origin first data
    }
};
void shuffle(char card[]) // to put card in random order
{
    srand(time(NULL));           // set the seed of random
    char temp;                   // declare a temp string to use to store
    int random = 0;              // declare a number will assigned by random
    for (int i = 0; i < 13; i++) // change every card
    {
        random = rand() % 13; // there is 13 card in it
        temp = card[i];       // swap the every card
        card[i] = card[random];
        card[random] = temp; // finish one time swap
    }
}
int main()
{                                                                                        //for the convenience,to make ten to T,after do it ,can store in a char array
    char origin[14] = {'K', 'Q', 'J', 'T', '9', '8', '7', '6', '5', '4', '3', '2', 'A'}; // the order want to drawn out
    char card[14] = {'K', 'Q', 'J', 'T', '9', '8', '7', '6', '5', '4', '3', '2', 'A'};   // the card's array
    shuffle(card);                                                                       // to put the card in random order
    LinkedList thecard;                                                                  //use linked list to move the card and drawn the card
    for (int i = 0; i < 13; i++)
        thecard.Push_back(card[i]); //push the card in it in the order,beacause it has been shuffled
    for (int n = 0; n < 13;)        // to drawn out the card in order
    {
        thecard.PrintList();                 // print thecard linked list
        if (thecard.getfirst() == origin[n]) //to see whether the top of card is wanted to draw
        {
            thecard.takeout(); // draw it away
            n++;               // to find next card
        }
        else
            thecard.Push_back(thecard.takeoutwhat()); //put the first card to the end of linked list
    }
}
