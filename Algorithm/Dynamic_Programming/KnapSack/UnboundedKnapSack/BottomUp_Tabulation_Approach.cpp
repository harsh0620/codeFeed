#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

/*
Q.Unbounded KnapSack Problem
Desc- This probelm states that you have two arrays 
(i).A value array 'val[]' and 
(ii).a weight array 'wt[]' and a limit variable generally named Weight 'W'
We have to maximize the value when we pick items from weight array corresponding to val[] array without exceeding the value W.
*/

/*
DSA-NOTES
1.Unbounded KnapSack DP Problem-Tabulation BottomUp Approach
2.In this we consider approcach that either we pick the element or we do not pick the element and then consider maximum of its value.
3.DP array will be filled like this dp[n+1][W+1] :. n=no. of elements, W=totalWeight;
4.dp[i][j]=Maximum value that we can collect with first i items and knapsack capacity j.
5.Base Case would be either elements get empty or Total Weight get Zero.
*/

int max(int a, int b) { return (a > b) ? a : b; }

int knapsack(int W, int wt[], int val[], int n)
{
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i][j - wt[i - 1]]);
            }
        }
    }
    return dp[n][W];
}
int main()
{
    int val[] = {10, 40, 30, 50};
    int wt[] = {5, 4, 6, 3};
    int W = 10;
    int n = 4;

    cout << knapsack(W, wt, val, n);
    return 0;
}

/*
Time Complexity: O(N*W). 
where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
Auxiliary Space: O(N*W). 
The use of 2-D array of size ‘N*W’
*/