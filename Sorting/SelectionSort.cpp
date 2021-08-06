#include <bits/stdc++.h>
using namespace std;

/*
In selection sort we just swap next smaller elements with the index of 
minimum value till now.

*/

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int a[], int n)
{
    int min_idx;
    for (int i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[min_idx] > a[j])
            {
                min_idx = j;
            }
        }
        swap(&a[min_idx], &a[i]);
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
    selectionSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
//                  Best	Average	Worst
// Selection Sort   Ω(n^2)	θ(n^2)	O(n^2)
// Auxiliary Space: O(1)