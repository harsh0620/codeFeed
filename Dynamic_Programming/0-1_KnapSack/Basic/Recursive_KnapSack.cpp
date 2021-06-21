#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

/*
Q.0/1 KnapSack Problem
Desc- This probelm states that you have two arrays 
(i).A value array 'val[]' and 
(ii).a weight array 'wt[]' and a limit variable generally named Weight 'W'
We have to maximize the value when we pick items from weight array corresponding to val[] array without exceeding the value W.
*/

/*
DSA-NOTES
1.0-1 KnapSack DP Problem-Recursive Approach
2.In this we consider approcach that either we pick the element or we do not pick the element and then consider maximum of its value.
3.Base Case would be either elements get empty or Total Weight get Zero.
*/

int max(int a, int b) { return (a > b) ? a : b; }

int knapsack(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }

    if (wt[n - 1] > W)
    {
        return knapsack(W, wt, val, n - 1);
    }
    else
    {
        return max(knapsack(W, wt, val, n - 1), val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1));
    }
}
int main()
{
    int val[] = {10, 40, 30, 50};
    int wt[] = {5, 4, 6, 3};
    int W = 10;
    int n = 4;
    cout << knapsack(W, wt, val, n);
    return 0;
}

/*
Time Complexity: O(2n). 
As there are redundant subproblems.
Auxiliary Space :O(1). 
As no extra data structure has been used for storing values.
*/