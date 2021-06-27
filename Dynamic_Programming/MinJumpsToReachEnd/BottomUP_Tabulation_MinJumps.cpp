#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

/*
Q.Minimum Jumps to Reach End Problem
Desc- This probelm states that you have one array and you can jump forward acc. to 
ith value of array going from left to right.
Now you have to find min. jumps to reach and end of the array.
*/

/*
DSA-NOTES
1.Minimum Jumps to Reach End Problem-BottomUp Tabulation Approach
2.In this we will take 1D array of size n and initialize it with infinity.
3.At position 0 we fill it with 0 as if length is 1 then we do not have to move to reach end.
4.Then we run two loop
(i)Outer one from 0->n
(ii)Inner one from 0->i
and we check if it is possible to reach from that position to i
and take minimum of them. 
*/

int minJumps(int a[], int n)
{
    int dp[n];
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = INT_MAX;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] + j >= i)
            {
                if (dp[j] != INT_MAX)
                {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
    }
    return dp[n - 1];
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
    cout << minJumps(a, n) << endl;
    return 0;
}

/*
Time Complexity: O(2^n). 
As there are redundant subproblems.
*/