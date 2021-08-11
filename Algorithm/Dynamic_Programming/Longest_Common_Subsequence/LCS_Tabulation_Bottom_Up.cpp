#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

/*
Problem - Longest Common Subsequence
In this problem we have given two string a and b and we have to find longest common subsequence
present in both the strings. 
*/

/*
DSA-Notes:-Tabulation Approach
1.In this we gonna prefer traversing from last.
2. If both element are equal on respectives position then we add 1.
3. If not equal then we take maximum of 
(i).Consider removing element from a 
(ii).Consider removing element from b;
4.To implement tabulation approach we take 2d array of +1 length of both the strings.
5.To handle the base case when either of the string length is zero we initialize i=0 and j=0 as 0;
6.And to fill the rest array we will go for steps 2 and 3.
*/

int lcs(string a, string b, int n, int m)
{
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}
int main()
{
    string a, b;
    cin >> a >> b;
    int n = a.length();
    int m = b.length();
    cout << lcs(a, b, n, m);
    return 0;
}

/*
Time Complexity:-
1.O(nm);
*/