#include <iostream>
#include <vector>
using namespace std;
vector<int> heap;          //the max heap
void push(int n);          //push the into heap
int pop();                 //pop the max
void swap(int *a, int *b); //the swap two nodes
int main()
{
    int time;    //how many time to enter
    cin >> time; //enter the time
    int M, N;    //M is the row ,N is the fans
    int X;       //X is empty seats
    int temp;    //to store the pop result
    int sum;     // the sum

    while (time--)
    {
        sum = 0;           //initialize sum to 0
        heap.resize(1, 0); // initialize the heap
        cin >> M >> N;     //input the M and N

        while (M--)
        {
            cin >> X;
            push(X); //push the empty seats in
        }
        while (N--)
        {
            temp = pop();   //get the money
            push(temp - 1); //empty seat is getting -1,push it back to the heap
            sum += temp;    //store it in the sum
        }
        cout << sum << endl; //print the sum
    }
}

void push(int n)
{
    heap.push_back(n); //push n into the heap
    int i = heap.size() - 1;
    while ((i != 1) && heap[i] > heap[i / 2]) //make the node to appropriate site
    {
        swap(heap[i], heap[i / 2]); //check it's parent to decide change or not
        i /= 2;                     //keep go up
    }
}
int pop()
{
    if (heap.size() <= 1)
    {
        cout << "empty"; //check it's empty or not
        exit(-1);
    }
    int parent = 1;                  //parent index is 1
    int lchild = 2;                  //lchild index is 2
    int rchild = 3;                  //rchild index is 3
    int output = heap[1];            //get the max
    heap[1] = heap[heap.size() - 1]; //take last node to put on the root
    int temp;
    heap.erase(heap.begin() + heap.size() - 1); //delete the last node
    while (1)
    {
        temp = parent;
        if ((lchild <= (heap.size() - 1)) && (heap[lchild] > heap[temp]))
            temp = lchild; //check lchild is in the heap or not,and check it's value bigger or not

        if ((rchild <= (heap.size() - 1)) && (heap[rchild] > heap[temp]))
            temp = rchild; //check rchild is in the heap or not,and check it's value bigger or not

        if (temp != parent) //check whether temp modified
        {
            swap(heap[temp], heap[parent]); //swap it
            parent = temp;                  //make it go down to check
            lchild = 2 * parent;
            rchild = 2 * parent + 1;
        }
        else
            break; //the heap is ok and break
    }
    return output; //return the max
}
void swap(int *a, int *b) //the swap two nodes
{
    int temp = *a;
    *a = *b;
    *b = temp;
}