#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

/*
Problem - Longest Common Subsequence
In this problem we have given two string a and b and we have to find longest common subsequence
present in both the strings. 
*/

/*
DSA-Notes:-Memoization Approach
1.In this we gonna prefer traversing from last.
2. If both element are equal on respectives position then we add 1.
3. If not equal then we take maximum of 
(i).Consider removing element from a 
(ii).Consider removing element from b;
4.Base case would be when any of the string length got zero
as when this happens we can not go further finding subsequence
5.We gonna take 2D memo array and initialize it with -1.
6.If memo array value is not equal to -1 then we gonna return our answer.
7.Else we proceed with steps 2 and 3.
*/

int lcs(string a, string b, int n, int m)
{
    int memo[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            memo[i][j] = -1;
        }
    }
    if (memo[n][m] != -1)
    {
        return memo[n][m];
    }
    if (n == 0 || m == 0)
    {
        memo[n][m] = 0;
    }
    else
    {
        if (a[n - 1] == b[m - 1])
        {
            memo[n][m] = 1 + lcs(a, b, n - 1, m - 1);
        }
        else
        {
            memo[n][m] = max(lcs(a, b, n - 1, m), lcs(a, b, n, m - 1));
        }
    }

    return memo[n][m];
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