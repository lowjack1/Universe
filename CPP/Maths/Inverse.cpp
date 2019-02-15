/* Calculate Inverse of all integers modulo given integer upto 10000000 */

#include <iostream>

using namespace std;
using ll = long long;
const int mod = 1000000007;

inline ll add(ll x, ll y) { x += y; if(x >= mod) x -= mod; return x; }
inline ll sub(ll x, ll y) { x -= y; if(x < 0) x += mod; return x; }
inline ll mul(ll x, ll y) { return ((x % mod) * (y % mod)) % mod; }


const int N1 = 10000004;
ll pre_inv[N1];
void inverse()
{
    pre_inv[1] = pre_inv[0] = 1;
    for(ll i = 2; i < N1; i ++) {
        ll x = mod % i;
        pre_inv[i] = (mod - (mod / i)) * pre_inv[x] % mod;
    }
}

int main()
{
    inverse();
    cout << pre_inv[10012];
    return 0;
}
