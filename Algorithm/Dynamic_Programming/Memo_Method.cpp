#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;
/*
DSA-NOTES
1.Example of memoization way of DP where we use memo array to store our results.
2.It is a top down approach.
*/

/*Q.DP-Memoization solution of fibonacci No.*/

int dp[MAX] = {-1};
int fib(int n)
{
    int res;
    if (n == 0 || n == 1)
    {
        res = n;
    }
    else
    {
        res = fib(n - 1) + fib(n - 2);
    }
    dp[n] = res;
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
1.fib(n-1) rooted down to n-1;
2.While fib(n-2) rooted down to n-2;
3.When we combine both it will results to 2n-1 which simply results to O(n) time. 
*/