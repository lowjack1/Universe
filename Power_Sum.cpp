/*  Stirling Alogrithm

    x^k = sum (i = 1 to k) {k, i} * i! * ncr(x, i)
    sum (x = 0 to n) x^k
            = sum (i = 0 to k) {k, i} * i! * sum (x = 0 to n) nCr(x, i)
            = sum (i = 0 to k) {k, i} * i! * nCr(n + 1, i + 1)
            = sum (i = 0 to k) {k, i} * i! * (n + 1)! / ((i + 1)! * (n - i)!)
            = sum (i = 0 to k) {k, i} * ((n + 1) * n * (n - 1) * ..... * (n - i + 1)) / (i + 1)
    
    {k, i} = Stirling Number of Second Kind = {k - 1, i - 1} + i * {k - 1, i}

    Assuming x <= 1e18 and k <= 1e3
    
    Time Complexity: O(k*K)
*/

#include <iostream>
#include <string.h>

using ll = long long;

const ll mod = 1000000007;

inline ll add(ll x, ll y) { x += y; if(x >= mod) x -= mod; return x; }
inline ll sub(ll x, ll y) { x -= y; if(x < 0) x += mod; return x; }
inline ll mul(ll x, ll y) { return ((x % mod) * (y % mod)) % mod; }

int main()
{
    ll x = 10, k = 10;
    std::cin >> x >> k;

    ll S[1002][1002];
    memset(S, 0, sizeof(S));
    S[1][1] = 1;
    for(int i = 2; i <= k; i ++) {
        for(int j = 1; j <= k; j ++) {
            S[i][j] = add(S[i - 1][j - 1], mul(j, S[i - 1][j]));
        }
    }
    ll ans = 0;
    for(ll i = 1; i <= k; i ++) {
        ll d = i + 1;
        ll res = 1;
        for(ll j = x + 1; j >= x - i + 1; j --) {
            ll u = j;
            if(u % d == 0) {
                u /= d;
                d /= d;
            }
            res = mul(u, res);
        }
        ans = add(ans, mul(res, S[k][i]));
    }
    std::cout << ans;
    return 0;
}
