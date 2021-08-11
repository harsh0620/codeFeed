#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

/*
Q.0/1 KnapSack Problem
Desc- This probelm states that you have two arrays 
(i).A value array 'val[]' and 
(ii).a weight array 'wt[]' and a limit variable generally named Weight 'W'
We have to maximize the value when we pick items from weight array corresponding to val[] array without exceeding the value W.
*/

/*
DSA-NOTES
1.0-1 KnapSack DP Problem-Memoization TopDown Approach
2.In this we consider approcach that either we pick the element or we do not pick the element and then consider maximum of its value.
3.DP array will be filled like this dp[n+1][W+1] :. n=no. of elements, W=totalWeight;
4.dp[i][j]=Maximum value that we can collect with first i items and knapsack capacity j.
5.Base Case would be either elements get empty or Total Weight get Zero.
*/

int max(int a, int b) { return (a > b) ? a : b; }
int dp[100][1000];
int knapsack(int W, int wt[], int val[], int n)
{
    if (n < 0)
        return 0;
    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }

    if (wt[n] > W)
    {
        dp[n][W] = knapsack(W, wt, val, n - 1);
        return dp[n][W];
    }
    else
    {
        dp[n][W] = max(knapsack(W, wt, val, n - 1), val[n] + knapsack(W - wt[n], wt, val, n - 1));
        return dp[n][W];
    }
}
int main()
{
    int val[] = {10, 40, 30, 50};
    int wt[] = {5, 4, 6, 3};
    int W = 10;
    int n = 4;
    memset(dp, -1, sizeof(dp));
    cout << knapsack(W, wt, val, n);
    return 0;
}

/*
Time Complexity: O(N*W). 
As redundant calculations of states are avoided.
Auxiliary Space: O(N*W). 
The use of 2D array data structure for storing intermediate states-:
*/