#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

/*
Q.0/1 KnapSack Problem- Target Sum

Problem Statement :---We have an array with some elements and 
a sum and we have to assign either + or - to elements and find how many combinations 
are their which results the sum equal to given sum.
*/

/*
DSA-NOTES
***This is duplication of Count of subsetDifference-basically it is one step ahead.
Here we are assigning + or - which is same as dividing array into two subset.
1.This problem is just same as the count of subset sum problem but with
some tweaks.
2.By reading problem statment we can form a equation like this:
S2-S1=diff;
and we know S2+S1=totalSum;
when we add both we get S2=(diff+totalSum)/2;
3.Now the problem is same as count of subset sum as we have array 
and a sum and we have to count subsets.
*/

int knapsack(int W, int a[], int n)
{
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0)
            {
                dp[i][j] = 0;
            }
            if (j == 0)
            {
                dp[i][j] = 1;
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
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - a[i - 1]]);
            }
        }
    }
    return dp[n][W];
}
int main()
{
    int a[] = {1, 1, 2, 3};
    int diff = 1;
    int n = 4;
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += a[i];
    }
    int W = (diff + totalSum) / 2;

    cout << knapsack(W, a, n);
    return 0;
}

/*
Time Complexity: O(sum*n), 
where sum is the ‘target sum’ and ‘n’ is the size of array.
Auxiliary Space: O(sum*n), 
as the size of 2-D array is sum*n.
*/