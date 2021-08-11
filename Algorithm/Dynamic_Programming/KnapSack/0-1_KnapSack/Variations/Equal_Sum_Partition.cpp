#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

/*
Q.0/1 KnapSack Problem- Equal Sum Partition Problem

Problem Statement :---We have an array with some elements
and we have to find that it is possible to extract two array from the given array
whose sums are equal.
*/

/*
DSA-NOTES
1.This problem is just a upper step of subset sum problem.
2.In this we have to first consider if sum is even or odd;
3.If odd then answer will be false bcoz we cannot divide array with odd sum.
4.If even then we have to just check subset sum problem with half of sum of array.
*/

bool knapsack(int W, int a[], int n)
{
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0)
            {
                dp[i][j] = false;
            }
            if (j == 0)
            {
                dp[i][j] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (a[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - a[i - 1]]);
            }
        }
    }
    return dp[n][W];
}
int main()
{
    int a[] = {1, 5, 11, 5};
    int W = 0;
    int n = 4;
    for (int i = 0; i < n; i++)
    {
        W += a[i];
    }
    if (W % 2 != 0)
    {
        cout << false << endl;
    }
    else
    {
        W = W / 2;
        cout << knapsack(W, a, n);
    }

    return 0;
}

/*
Time Complexity: O(sum*n), 
where sum is the ‘target sum’ and ‘n’ is the size of array.
Auxiliary Space: O(sum*n), 
as the size of 2-D array is sum*n.
*/