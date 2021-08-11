#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;
/*
DSA-NOTES
1.Example of Tabulation way of DP where we use 1D or 2D array to store our pre results.
2.It is a Bottom Up approach.
*/

/*Q.DP-Tabulation solution of fibonacci No.*/

int fib(int n)
{
    int dp[n + 1] = {0};
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}

/*
Time Complexity:-
1.As we are simply looping it takes O(n)time;
2.Auxillary Space of O(n)space; 
*/