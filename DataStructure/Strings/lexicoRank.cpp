#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int lexRank(string s)
{
    int rank = 1;

    int count[256] = {0};

    int n = s.length();
    int mul = factorial(n);

    for (int i = 0; i < n; i++)
    {
        count[s[i]]++;
    }
    for (int i = 1; i < 256; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        mul = mul / (n - i);
        rank = rank + (count[s[i]] - 1) * mul;
        for (int j = s[i]; j < 256; j++)
        {
            count[j]--;
        }
    }
    return rank;
}

int main()
{

    string s;
    cin >> s;

    cout << lexRank(s) << endl;

    return 0;
}
