#include <bits/stdc++.h>
using namespace std;

// important definitions
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

// VERY USEFUL THINGS
vector<ll> sieve(int n) // VECTOR IF PRIME NUMBERS UPTO A NUMBER N.
{
    int *arr = new int[n + 1]();
    vector<ll> vect;
    for (int i = 2; i <= n; i++)
        if (arr[i] == 0)
        {
            vect.push_back(i);
            for (int j = 2 * i; j <= n; j += i)
                arr[j] = 1;
        }
    return vect;
}

ll gcd(ll a, ll b) // GCD OF TWO NUMBERS
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void swap(ll &a, ll &b) // SWAPPING TWO NUMBERS
{
    a = (a ^ b);
    b = (a ^ b);
    a = (a ^ b);
}

ll lcm(ll a, ll b)//LCM OF TWO NUMBERS
{
    return ((a * b) / gcd(a, b));
}

// TAKE INPUT'S + CREATE BASIS OF THE PROBLEM IN THIS FUNCTION.
void solution()
{
}

signed main()
{
    int tc = 1;
    cin >> tc;

    while (tc--)
    {
        solution();
    }
}