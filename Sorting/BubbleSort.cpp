#include <bits/stdc++.h>
using namespace std;

/*
In bubble Sort we just swap adjacent element if 
the index+1 is greater than index element.
In each ith iteration single element is sorted and 
stacked and the end of the array, that's why we 
iterate n-i-1 in second loop;

*/

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                flag = true;
            }
        }
        if (flag == false)
        {
            break;
        }
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
    bubbleSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
//                  Best	Average	Worst
// Selection Sort   Ω(n)	θ(n^2)	O(n^2)
// Auxiliary Space: O(1)