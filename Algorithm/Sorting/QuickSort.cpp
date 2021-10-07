#include <bits/stdc++.h>
using namespace std;

/*
In quick sort we use divide and conquer algorithm i.e. divide the 
problem into smaller problems.

In this we pick pivot element,the element whose left side elements
are smaller and right side elements are greater and by picking the element we 
also positioned it to its real pos. according to sorting.

*/

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int partition(int a[], int l, int h)
{
    int i = l;
    int j = h;
    int pivot = a[l];
    while (i < j)
    {
        do
        {
            i++;
        } while (a[i] <= pivot);
        do
        {
            j--;
        } while (a[j] > pivot);
        if (i < j)
        {
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[l], &a[j]);
    return j;
}
void quickSort(int a[], int l, int h)
{
    if (l < h)
    {
        int pi = partition(a, l, h);
        quickSort(a, l, pi);
        quickSort(a, pi + 1, h);
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
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
//                  Best	    Average	    Worst
// Quick Sort       Ω(n log(n))	θ(n log(n))	O(n^2)
// Auxiliary Space: O(1)