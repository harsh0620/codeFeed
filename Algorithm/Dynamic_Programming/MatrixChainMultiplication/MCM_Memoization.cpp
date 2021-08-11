#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

/*
Q.Matrix Chain Multiplication Problem-Recursive

Problem Statement :---We have an array with some elements and 
these elements represents the size of matrix and we have to find minimum number of steps
to multiply those matrices.
Constraints-
for n size array there will be n-1 matrix
and their size initializes as Ai=a[i-1]*a[i]->from i=1 to n-1
*/

/*
DSA-NOTES
1.In this problem we have to make partition in array to calculate
multiplication constraints for every combination we have for n-1 matrices.
2.And then minimum of it.
3.For that we loop from k=i=1 to k=j-1=n-1;Here K can be treated as partition index.
4.For this looping we recursively find minimum for i->k and k+1->j and then add them with
a[i-1]*a[k]*a[j];
Base case would be if i>j(length==0) or i==j(length=1);
5.For memoization we first take 2d array of size of given array and initialize it with -1;
6.And we only solve the condition if dp[i][j]==-1 else return dp[i][j] i.e. answer.
*/
int dp[100][100];
int mcm(int a[], int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        dp[i][j] = min(dp[i][j], mcm(a, i, k) + mcm(a, k + 1, j) + a[i - 1] * a[k] * a[j]);
    }
    return dp[i][j];
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
    memset(dp, -1, sizeof(dp));
    cout << mcm(a, 1, n - 1);
    return 0;
}
/*Time Complexity: O(n3 )
Auxiliary Space: O(n2)*/