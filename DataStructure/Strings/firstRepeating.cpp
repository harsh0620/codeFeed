#include <bits/stdc++.h>
using namespace std;

int firstRepeating(string s)
{
    int f[256] = {0};
    int res = INT_MAX;
    for (int i = 0; i < 256; i++)
    {
        f[i] = -1;
    }
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (f[s[i]] == -1)
        {
            f[s[i]] = i;
        }
        else
        {
            res = i;
        }
    }
    return (res == INT_MAX ? -1 : res);
}

int main()
{
    string s;
    cin >> s;

    cout << firstRepeating(s) << endl;

    return 0;
}
