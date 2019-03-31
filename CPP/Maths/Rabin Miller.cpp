/*
    Miller Rabin Primality Test
    Time Complexity = O(k * logn)
    Space Complexity = O(1)
*/

#include <iostream>
using namespace std;

using ll = long long;

ll mul(ll x, ll y, ll MOD) { return ((x % MOD) * (y % MOD)) % MOD; }
ll powr(ll a, ll b, ll MOD) {
    ll x = 1LL;
    while(b) {
        if(b & 1) x = mul(x, a, MOD);
        a = mul(a, a, MOD);
        b >>= 1;
    }
    return x;
}

bool rabinMiller(ll p)
{
    if(p == 1) return false;
    if(p == 2 or p == 3) return true;
    if(p % 2 == 0 or p % 3 == 0) return false;

    ll d = p-1;
    while(d%2 == 0) d /= 2;

    for(int i = 0; i < 35; i ++) {
        ll a = rand() % (p-1) + 1;
        ll tmp = d;
        ll x = powr(a, tmp, p);
        while(tmp != p-1 and x != 1 and x != p-1) {
            x = mul(x, x, p);
            tmp *= 2;
        }
        if(x != p-1 and tmp%2 == 0) return false;
    }
    return true;
}

int main()
{
    cout << rabinMiller(1203840382038) << "\n";
    return 0;
}
