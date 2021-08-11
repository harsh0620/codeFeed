#include <bits/stdc++.h>
using namespace std;

/*
In binary search we search in sorted array and constraint our search 
according to mid element and given element to find.

*/
int binarySearch(int a[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (a[mid] == x)
        {
            return mid;
        }

        if (a[mid] > x)
        {
            return binarySearch(a, l, mid - 1, x);
        }
        return binarySearch(a, mid + 1, r, x);
    }
    return -1;
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
    int x;
    cin >> x;
    cout << binarySearch(a, 0, n - 1, x);

    return 0;
}
// Time Complexity  θ(log(n))
// Auxiliary Space: O(1)