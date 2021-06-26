#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

/*
Problem - Edit Distance
In this problem we have given two string a and b and we have to calculate minimum
no. of steps to make them both equal using insertion deletion and replacing.
*/

/*
DSA-Notes:-Recursive Approach
1.In this we gonna prefer traversing from last.
2. If both element are equal on respectives position then we simply move forward and 
neglect them.
3.If not then we have to take min. of 3 choices and 1 to it (as we are choosing one operation)
(i).Either we insert element-in this one string's lenght will remain same
and other strings length will decrease.
(ii)Or we delete one of the char of strings -in this one string's lenght will remain same
and other strings length will decrease.
(iii).Or we replace both of the char in strings-in this both strings looses 1 char length.
4.Base cases would be when either of the string get 0 
then we return remaining length of the other string.

*/
int min(int a, int b) { return (a < b) ? a : b; }
int editDistance(string a, string b, int n, int m)
{
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
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
    cout << editDistance(a, b, n, m);
    return 0;
}

/*
Time Complexity:-
1.O(mn);
*/