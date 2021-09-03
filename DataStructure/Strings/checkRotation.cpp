#include <bits/stdc++.h>
using namespace std;

bool checkRotation(string a, string b)
{
    if (a.length() != b.length())
    {
        return false;
    }
    a = a + a;
    return (a.find(b) != string::npos);
}

int main()
{

    string a, b;
    cin >> a >> b;
    cout << checkRotation(a, b);

    return 0;
}
