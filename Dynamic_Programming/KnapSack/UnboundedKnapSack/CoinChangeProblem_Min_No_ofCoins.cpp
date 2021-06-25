#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

/*
Q.Unbounded KnapSack Problem- Coin Change Problem Minimum no. of coins to get given value

Problem Statement :---We have an array with some coins but they have infinite supply and a sum
and we have to find minimum no. of coins in which we can get the sum.
*/

/*
DSA-NOTES
1. In this we take 1D dp array of size sum+1 as only sum is varying.
2.We initialize the array with infinite
2.Sum with zero coins will be zero so dp[0]=0;
3.The approach here are as follows:
(i) We traverse in Dp array and for every index/sum we traverse in coins array
and for every coins less than equal to sum we 
count the no. of coins to get the sum.
(ii) And then we return min. of different no. of coins ways
(iii) And finally the min. no. of coins.
*/

int getMin(int W, int coins[], int n)
{
    int dp[W + 1];
    for (int j = 0; j <= W; j++)
    {
        dp[j] = INT_MAX;
    }
    dp[0] = 0;
    for (int i = 1; i <= W; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (coins[j] <= i)
            {
                int sub_res = dp[i - coins[j]];
                if (sub_res != INT_MAX)
                {
                    dp[i] = min(dp[i], sub_res + 1);
                }
            }
        }
    }
    return dp[W];
}
int main()
{
    int coins[] = {3, 4, 1};
    int W = 5;
    int n = 3;

    cout << getMin(W, coins, n);
    return 0;
}

/*
Time Complexity: O(W*n), 
where sum is the ‘target sum’ and ‘n’ is the size of array.
Auxiliary Space: O(W), 
as the size of 2-D array is sum*n.
*/