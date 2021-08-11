#include <bits/stdc++.h>
using namespace std;

/*
jump+linear search

jump upto the index greater then given element
then linear search from just back index to that index.

*/
int jumpSearch(int a[], int x, int n)
{
    int step = sqrt(n);

    int prev = 0;

    while (a[min(step, n) - 1] < x)
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
        {
            return -1;
        }
    }
    while (a[prev] < x)
    {
        prev++;

        if (prev == min(step, n))
        {
            return -1;
        }
    }
    if (a[prev] == x)
    {
        return prev;
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
    cout << jumpSearch(a, x, n);

    return 0;
}
// Time Complexity  θ(log(n))
// Auxiliary Space: O(1)