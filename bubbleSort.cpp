/*David Archer
Bubble Sort*/

#include<iostream>
using namespace std;

int swaps;
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            ++i;
        }
        else
        {
            arr[k] = R[j];
            ++j;
        }
        ++k;
        ++swaps;
    }


    while (i < n1)
    {
        arr[k] = L[i];
        ++i;
        ++k;
        ++swaps;
    }


    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
        swaps++;
    }
    delete[] L;
    delete[] R;
}


void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; ++j)
            if (arr[j] > arr[j + 1]) 
            {
                ++swaps;
                swap(arr[j], arr[j + 1]);
            }
}
int main()
{
    int arr1[10000];
    int seed;
    cout << "The seed to use is: ";
    cin >> seed;

    srand(seed);

    for (int i = 0; i < 10000; ++i) 
    {
        arr1[i] = rand() % 10000;
    }


    bubbleSort(arr1, 10000);

    cout << "\nBubble Sort had " << swaps << " swaps" << endl;

    cout << "The first 10 values: ";
    for (int i = 0; i < 10; ++i) 
    {
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "The last 10 values: ";
    for (int i = 9990; i < 10000; ++i) 
    {
        cout << arr1[i] << " ";
    }

    swaps = 0;
    cout << endl;
    srand(seed);

    for (int i = 0; i < 10000; ++i) 
    {
        arr1[i] = rand() % 10000;
    }


    mergeSort(arr1, 0, 10000 - 1);

    cout << "\nMerge Sort had " << swaps << " moves" << endl;
    cout << "The first 10 values: ";

    for (int i = 0; i < 10; ++i) 
    {
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "The last 10 values: ";
    for (int i = 9990; i < 10000; ++i) 
    {
        cout << arr1[i] << " ";
    }

    return 0;
}