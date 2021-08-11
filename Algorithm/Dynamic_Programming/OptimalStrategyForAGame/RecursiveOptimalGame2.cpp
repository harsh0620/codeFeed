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
1.Optimal Strategy For a game->Recursive Approach---2
2.In this we recursively call the function 4times.
3.Here we take minimum of option that our opponent has as both are playing optimally.
*/
int max(int a, int b) { return (a > b) ? a : b; }
int min(int a, int b) { return (a < b) ? a : b; }
int optimalGame(int a[], int i, int j)
{
    if (j == i + 1)
    {
        return max(a[i], a[j]);
    }

    return max((a[i] + min(optimalGame(a, i + 1, j - 1), optimalGame(a, i + 2, j))), (a[j] + min(optimalGame(a, i + 1, j - 1), optimalGame(a, i, j - 2))));
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
    }
    cout << optimalGame(a, 0, n - 1) << endl;
    return 0;
}

/*
Time Complexity: O(n^2). 
As there are two loops.
*/