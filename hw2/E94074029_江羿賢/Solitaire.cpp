#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory.h>
#include <string.h>
using namespace std;
void shuffle(char[][3]);        // to shuffle the card in random
void show(char[][3], int);      // to print the card
void putback(char[][3], int);   // to put the top of card to the end
void takeout(char[][3], int &); // to drawn out the top of card
int main()
{
    char origin[14][3] = {"K", "Q", "J", "10", "9", "8", "7", "6", "5", "4", "3", "2", "A"}; // the order want to drawn out
    char card[14][3] = {"K", "Q", "J", "10", "9", "8", "7", "6", "5", "4", "3", "2", "A"};   // the card's array
    int n = 13;                                                                              // the number of card in the array
    shuffle(card);                                                                           // to put the card in random order
    for (int i = 0; i < 13;)                                                                 // to drawn out the card in order
    {
        show(card, n);// show the card
        if (!strcmp(card[0], origin[i])) //to see whether the top of card is wanted to draw
        {
            takeout(card, n); // draw it away
            i++;              // to find next card
            cout << endl;
        }
        else
        {
            cout << endl;
            putback(card, n); // put the card to the end
        }
    }
}

void shuffle(char card[][3]) // to put card in random order
{
    srand(time(NULL));           // set the seed of random
    char temp[3];                // declare a temp string to use to store
    int random = 0;              // declare a number will assigned by random
    for (int i = 0; i < 13; i++) // change every card
    {
        random = rand() % 13;  // there is 13 card in it
        strcpy(temp, card[i]); // swap the every card
        strcpy(card[i], card[random]);
        strcpy(card[random], temp); // finish one time swap
    }
}

void show(char card[][3], int n) // show the card
{
    for (int i = 0; i < n; i++)
    {
        cout << card[i] << " "; // show form the top to the end
    }
}

void putback(char card[][3], int n) // put the top of card to the end
{
    char temp[3];          // declare a temp string to use to store
    strcpy(temp, card[0]); // store the top of card
    for (int i = 0; i < n - 1; i++)
    {
        strcpy(card[i], card[i + 1]); // make others card move
    }
    strcpy(card[n - 1], temp); // put the top of card to the end
}

void takeout(char card[][3], int &n) // to take out the card
{
    for (int i = 0; i < n - 1; i++)
    {
        strcpy(card[i], card[i + 1]); // make others card move
    }
    memset(card[n - 1], 0, 3);  // make end of card to initialize
    n--;   // make number of card in array minus 1
}
