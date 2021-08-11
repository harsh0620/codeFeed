#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

/*
Q.Unbounded KnapSack Problem- Coin Change Problem

Problem Statement :---We have an array with some coins but they have infinite supply and a sum
and we have to find total ways in which we can get the sum.
*/

/*
DSA-NOTES
1. In this we consider same conditions as 0/1 knapsack.
2.But in this we first not consider the element without any condition.
3.And if the coins at that position is less than equal to sum then we consider that coin
4.Base case would be that 
(i). If the sum is zero than we have one way to take the empty array
(ii).If the elements is zero then the no. will also be zero.
5. We take 2d DP array with length dp[sum+1][n+1].
6.Here dp[i][j]->No. of combination we can get with sum i and coins from 1 to j.
*/

int knapsack(int W, int coins[], int n)
{
    int dp[W + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = 1;
    }
    for (int j = 1; j <= W; j++)
    {
        dp[j][0] = 0;
    }
    for (int i = 1; i <= W; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i][j - 1];
            if (coins[j - 1] <= i)
            {
                dp[i][j] += dp[i - coins[j - 1]][j];
            }
        }
    }
    return dp[W][n];
}
int main()
{
    int coins[] = {1, 2, 3};
    int W = 4;
    int n = 3;

    cout << knapsack(W, coins, n);
    return 0;
}

/*
Time Complexity: O(sum*n), 
where sum is the ‘target sum’ and ‘n’ is the size of array.
Auxiliary Space: O(sum*n), 
as the size of 2-D array is sum*n.
*/