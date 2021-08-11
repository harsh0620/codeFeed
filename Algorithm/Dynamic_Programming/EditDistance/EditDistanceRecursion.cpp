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

int editDistance(string a, string b, int n, int m)
{
    if (n == 0)
    {
        return m;
    }
    if (m == 0)
    {
        return n;
    }
    if (a[n - 1] == b[m - 1])
    {
        return editDistance(a, b, n - 1, m - 1);
    }
    else
    {
        return 1 + min(editDistance(a, b, n - 1, m), min(editDistance(a, b, n - 1, m - 1), editDistance(a, b, n, m - 1)));
    }
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
1.O(2^n);
*/