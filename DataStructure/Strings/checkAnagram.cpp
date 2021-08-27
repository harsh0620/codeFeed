#include <bits/stdc++.h>
using namespace std;

bool checkAnagram(string a, string b)
{
    if (a.length() != b.length())
    {
        return false;
    }
    int f[256] = {0};
    for (int i = 0; i < a.length(); i++)
    {
        f[a[i]]++;
    }
    for (int i = 0; i < b.length(); i++)
    {
        f[b[i]]--;
    }
    for (int i = 0; i < 256; i++)
    {
        if (f[i] != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string a, b;
    cin >> a >> b;

    cout << (checkAnagram(a, b) == true ? "Yes"
                                        : "No")
         << endl;

    return 0;
}
