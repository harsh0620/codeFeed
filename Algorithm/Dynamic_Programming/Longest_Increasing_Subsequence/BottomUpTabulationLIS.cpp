#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

/*
Problem - Longest Increasing Subsequence
In this problem we have given an array and we have to find longest increasing subsequece
means array in increasing order.
*/

/*
DSA-Notes:-Tabulation Approach
1. In this we use 1D array to store the LIS of every element 
and then take maximum of them.
2.To find the lis of ith element we traverse backward
and for every element that is less than ith element we take it lis and add 1 to it
and then take maximum of it.
3.Base Case would be lis[0]=1;
*/

int lis(int a[], int n)
{
    int lis[n];
    lis[0] = 1;
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
        ans = max(ans, lis[i]);
    }
    return ans;
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
    cout << lis(a, n);
    return 0;
}

/*
Time Complexity:-
1.O(nm);
*/