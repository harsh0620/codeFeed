#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

/*
Q.0/1 KnapSack Problem- Count of Subsets Sum with a given sum

Problem Statement :---We have an array with some elements and a sum 
and we have to find no. of subset array 
present in given array whose sum is equal to the given sum.
*/

/*
DSA-NOTES
1.In this we are considering either true or false so the arrays will be initialize with 1/0;
2.for i-> rows we will take array's size and fot j-> columns we will take sum;
3. for i==0 value of array will be 0 except (0,0) as with empty array we can not make sum;
4. for j==0 value of array will be 1 as we can always get sum 0 
either there are element in array or not i.e. {} empty array;
5.In this all the things are just similar as subset sum problem 
with a basic modification of change of || with + bcoz we have to find total no. of subsets
rather than just returning true or false.
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
    int a[] = {2, 3, 5, 6, 8, 10};
    int W = 10;
    int n = 6;

    cout << knapsack(W, a, n);
    return 0;
}

/*
Time Complexity: O(sum*n), 
where sum is the ‘target sum’ and ‘n’ is the size of array.
Auxiliary Space: O(sum*n), 
as the size of 2-D array is sum*n.
*/