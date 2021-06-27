#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

/*
Q.Minimum Jumps to Reach End Problem
Desc- This probelm states that you have one array and you can jump forward acc. to 
ith value of array going from left to right.
Now you have to find min. jumps to reach and end of the array.
*/

/*
DSA-NOTES
1.Minimum Jumps to Reach End Problem-Recursive Approach
2.In this problem we first check that from which position we can reach end 
which is easy just by travesring 
3. After that for every true condition we check recursively the same condition for that element.

*/

int minJumps(int a[], int n)
{
    if (n == 1)
    {
        return 0;
    }
    int res = INT_MAX;
    for (int i = 0; i <= n - 2; i++)
    {
        if (i + a[i] >= n - 1)
        {
            int sub_res = minJumps(a, i + 1);
            if (sub_res != INT_MAX)
            {
                res = min(res, sub_res + 1);
            }
        }
    }
    return res;
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
    cout << minJumps(a, n) << endl;
    return 0;
}

/*
Time Complexity: O(2n). 
As there are redundant subproblems.
Auxiliary Space :O(1). 
As no extra data structure has been used for storing values.
*/