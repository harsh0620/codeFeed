#include <bits/stdc++.h>
using namespace std;

int firstNonRepeating(string s)
{
    int f[256] = {0};
    int res = INT_MAX;
    for (int i = 0; i < 256; i++)
    {
        f[i] = -1;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (f[s[i]] == -1)
        {
            f[s[i]] = i;
        }
        else
        {
            f[s[i]] = -2;
        }
    }
    for (int i = 0; i < 256; i++)
    {
        if (f[i] >= 0)
        {
            res = min(res, f[i]);
        }
    }
    return (res == INT_MAX ? -1 : res);
}

int main()
{
    string s;
    cin >> s;

    cout << firstNonRepeating(s) << endl;

    return 0;
}
