#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

/*
Q.Optimal Strategy For a game
Desc- This problem states that you have an array and two players and in each turn 
one of them choose element from the array and both try to maximize their value.
In this problem you go first.
You have to find maximum value you can get if both players play optimally.
*/

/*
DSA-NOTES
1.Optimal Strategy For a game->Bottom Up Tabulation Optimal Game
2.In this we use 2D array as there are two variables.
3.In this we follow non-standard fashion of filling the table.
4.Here our answer is dp[0][n-1] as we have to take total n elements.
5.We fill the dp array in diagonal fashion starting at j=1 position.
for ex-dp[6][6]
0 * 0 * 0 *
0 0 * 0 * 0
0 0 0 * 0 *
0 0 0 0 * 0
0 0 0 0 0 *
0 0 0 0 0 0
Here we fill only upper matrix triangle as the base condition do not allow j!=i+1; 
*/
int max(int a, int b) { return (a > b) ? a : b; }
int min(int a, int b) { return (a < b) ? a : b; }
int optimalGame(int a[], int n)
{
    int dp[n][n];

    int j;
    for (int i = 0; i < n - 1; i++)
    {
        dp[i][i + 1] = max(a[i], a[i + 1]);
    }
    for (int gap = 3; gap < n; gap = gap + 2)
    {
        for (int i = 0; (i + gap) < n; i++)
        {
            j = i + gap;
            dp[i][j] = max(a[i] + min(dp[i + 2][j], dp[i + 1][j - 1]),
                           a[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
        }
    }
    return dp[0][n - 1];
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
    cout << optimalGame(a, n) << endl;
    return 0;
}

/*
Time Complexity: O(n^2). 
As there are two loops.
*/