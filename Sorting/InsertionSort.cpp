#include <bits/stdc++.h>
using namespace std;

/*
Insertion sort is reverse of selection sort.
In this we pick ith element and loop backwards 
and swap elements until we go to the index where
elements is less then the picked element;
*/

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void insertionSort(int a[], int n)
{
    int key;
    for (int i = 1; i < n; i++)
    {
        key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    insertionSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
//                  Best	Average	Worst
// Insertion Sort   Ω(n)	θ(n^2)	O(n^2)
// Auxiliary Space: O(1)