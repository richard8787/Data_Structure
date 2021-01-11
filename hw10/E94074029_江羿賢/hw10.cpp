#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;
void swap(int *a, int *b);
int Partition(int *a, int left, int right);
void QuickSort(int *a, int left, int right);
int Partition_median(int *a, int left, int right);
void QuickSort_median(int *a, int left, int right);
void print(int *a, int size);
int main()
{
    int a[500000] = {}; //declare the array

    //readfile
    FILE *fp;                    //for do fopen
    fp = fopen("hw10.txt", "r"); //open the file and input data
    int input;                   //the temp input
    int i = 0;                   //the index of array
    if (fp != NULL)
    {
        while (!feof(fp))
        {
            fscanf(fp, "%d", &input);
            a[i] = input; //input into array
            i++;
            if (i >= 500000) //shut down the input before over the array size
                break;
        }
        //cout << "readfile ok!" << endl;
    }
    else
    {
        //cout<<"Error"
        fclose(fp);
        return 0;
    }
    fclose(fp); //close the file
    //readfile end

    //count time
    clock_t start, right;//delare the time number
    double cpu_time_used;//store the time

    start = clock();
    //QuickSort(a, 0, 150000);//left most version
    QuickSort_median(a, 0, 150000); //median version
    right = clock();
    cpu_time_used = ((double)(right - start)) / CLOCKS_PER_SEC;//count the time
    //printf("use leftmost and longer first execution time = %f\n", cpu_time_used);
    //printf("use leftmost and shorter first execution time = %f\n", cpu_time_used);
    //printf("use leftmost and original execution time = %f\n", cpu_time_used);
    //printf("use median of three and longer first execution time = %f\n", cpu_time_used);
    //printf("use median of three and shorter first execution time = %f\n", cpu_time_used);
    printf("use median of three and original execution time = %f\n", cpu_time_used);
    //count time end
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition_median(int *a, int left, int right) //do partition_median version
{
    //median of three
    int x = (left + right) / 2; //do sort of these three number
    if (a[left] > a[x])
        swap(&a[left], &a[x]);
    if (a[x] > a[right])
        swap(&a[x], &a[right]);
    if (a[left] > a[x])
        swap(&a[left], &a[x]);

    swap(&a[left + 1], &a[x]); //put the pivot to the new left most
    left++;                    //avoid unnecessary count
    right--;                   //avoid unnecessary count
    //median of three end
    int pivot = a[left];//set the pivot on leftmost
    int j = right + 1;
    for (int i = right; i > left; i--)//put the number to appropriate site
    {
        if (pivot < a[i])//to check whether bigger than pivot or not
        {
            j--;
            swap(&a[j], &a[i]);
        }
    }
    j--;
    swap(&a[left], &a[j]);//set the pivot to appropriate site

    return j;//return pivot position
}

void QuickSort_median(int *a, int left, int right) //do quick sort_median version(choose mode below the code)
{
    if (left < right)
    {
        int pivot = Partition_median(a, left, right);//partition and get pivot
        //original
        QuickSort_median(a, left, pivot - 1);
        QuickSort_median(a, pivot + 1, right);

        //longer first
        /*if (pivot - 1 - left > right - pivot - 1)
        {
            QuickSort_median(a, left, pivot - 1);
            QuickSort_median(a, pivot + 1, right);
        }
        else
        {
            QuickSort_median(a, pivot + 1, right);
            QuickSort_median(a, left, pivot - 1);
        }*/

        //shorter first
        /*if (pivot - 1 - left < right - pivot - 1)
        {
            QuickSort_median(a, left, pivot - 1);
            QuickSort_median(a, pivot + 1, right);
        }
        else
        {
            QuickSort_median(a, pivot + 1, right);
            QuickSort_median(a, left, pivot - 1);
        }*/
    }
}

int Partition(int *a, int left, int right) //do partition
{
    int pivot = a[left];//set the pivot on leftmost
    int j = right + 1;
    for (int i = right; i > left; i--)//put the number to appropriate site
    {
        if (pivot < a[i])//to check whether bigger than pivot or not
        {
            j--;
            swap(&a[j], &a[i]);
        }
    }
    j--;
    swap(&a[left], &a[j]);//set the pivot to appropriate site

    return j;//return pivot position
}

void QuickSort(int *a, int left, int right) //do quick sort(choose mode below the code)
{
    if (left < right)
    {
        int pivot = Partition(a, left, right);//partition and get pivot
        //original
        QuickSort(a, left, pivot - 1);
        QuickSort(a, pivot + 1, right);

        //longer first
        /*if (pivot - 1 - left > right - pivot - 1)
        {
            QuickSort(a, left, pivot - 1);
            QuickSort(a, pivot + 1, right);
        }
        else
        {
            QuickSort(a, pivot + 1, right);
            QuickSort(a, left, pivot - 1);
        }*/

        //shorter first
        /*if (pivot - 1 - left < right - pivot - 1)
        {
            QuickSort(a, left, pivot - 1);
            QuickSort(a, pivot + 1, right);
        }
        else
        {
            QuickSort(a, pivot + 1, right);
            QuickSort(a, left, pivot - 1);
        }*/
    }
}

void print(int *a, int size) //print the array for test
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
