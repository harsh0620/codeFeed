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
*/

int mcm(int a[], int i, int j)
{
    if (i >= j)
    {
        return 0;
    }
    int mn = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int tempans = mcm(a, i, k) + mcm(a, k + 1, j) + a[i - 1] * a[k] * a[j];
        if (tempans < mn)
        {
            mn = tempans;
        }
    }
    return mn;
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
    cout << mcm(a, 1, n - 1);
    return 0;
}
