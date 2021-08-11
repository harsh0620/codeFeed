#include <bits/stdc++.h>
using namespace std;

vector<bool> sieveOfEratosthenes(int n)
{
    vector<bool> prime(n + 1, true);

    prime[0] = false;
    prime[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        for (int j = 2 * i; j <= n; j += i)
        {
            prime[j] = false;
        }
    }
    return prime;
}
int gcd(int a, int b)
{
    return a % b == 0 ? b : gcd(b, a % b);
}
long fastPower(long a, long b, int n)
{
    long res = 1;
    while (b > 0)
    {
        if ((b & 1) != 0)
        {
            res = (res * a % n) % n;
        }
        a = (a % n * a % n) % n;
        b = b >> 1;
    }
    return res;
}
int main()
{
    /*Sieve*/
    // int n;
    // cin >> n;
    // vector<bool> ans = sieveOfEratosthenes(n);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     if (ans[i] == true)
    //     {
    //         cout << i << " ";
    //     }
    // }

    // Time Complexity  θ(root(n))
    // Auxiliary Space: O(n)
    /*Sieve*/

    /*GCD*/
    // int a, b;
    // cin >> a >> b;
    // cout << gcd(a, b) << endl;

    // Time Complexity  θ(log(n))
    // Auxiliary Space: O(1)
    /*GCD*/

    /*Fast Power*/
    // int n, m;
    // cin >> n >> m;
    // cout << fastPower(n, m, 100000009);
    // Time Complexity  θ(log(m))
    // Auxiliary Space: O(1)
    /*Fast Power*/
    return 0;
}
/*Sieve*/

/*Sieve*/
