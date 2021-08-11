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
1.Optimal Strategy For a game->Recursive Approach---1
2.In this we call recursive optimally for opponent and subtract that value from total sum
3.And we do same with ourselves and then take maximum of it.
4.Base case would be when there are only two element left then we take max of both of them.
*/
int max(int a, int b) { return (a > b) ? a : b; }
int optimalGame(int a[], int i, int j, int sum)
{
    if (j == i + 1)
    {
        return max(a[i], a[j]);
    }

    return max(sum - optimalGame(a, i + 1, j, sum - a[i]),
               sum - optimalGame(a, i, j - 1, sum - a[j]));
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    cout << optimalGame(a, 0, n - 1, sum) << endl;
    return 0;
}

/*
Time Complexity: O(n^2). 
As there are two loops.
*/