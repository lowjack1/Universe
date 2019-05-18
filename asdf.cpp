/*input
6 6
4
2
6
5
1
3

*/

#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <utility>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb          push_back
#define pp          pop_back
#define nl          cout << "\n"
#define MIN(con)    (*min_element(ALL(con)))
#define MAX(con)    (*max_element(ALL(con)))
#define NX(cont)    next_permutation(ALL(cont))
#define PX(cont)    prev_permutation(ALL(cont))
#define prec(n)     cout << fixed << setprecision(n)
#define PI          3.14159265358979323846264338327951
#define all(c)      c.begin(),c.end()
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define sp          cout << " "
#define ifalse      ios_base::sync_with_stdio(false),cin.tie(NULL)
#define debug(x)    cout << #x << " = " << x << "\n";

using ll = long long;
using ld = long double;
 
template <typename T> T GCD(T a, T b) { ll t; while(a){ t=a; a=b%a; b=t; } return b; }
template <typename T> T LCM(T a, T b) { return (a*b) / GCD(a, b); }
template <typename T> string toString(T a) { return to_string(a); }
template <typename T> void toInt(string s, T &x) { stringstream str(s); str >> x; }

ll add(ll x, ll y, ll MOD) { x += y; x %= MOD; return x; }
ll sub(ll x, ll y, ll MOD) { x -= y; x = (x + MOD) % MOD; return x; }
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

ll inv(ll a, ll MOD) { return powr(a, MOD-2, MOD); }
const ll INF =  1000000000000000018;
const int SINF = 1000000009;
ll MOD = 1000000007;

bool check(ll n)
{
  if(n == 1) return 0;
  if(n == 2 or n == 3) return 1;
  if(n%2 == 0 or n%3 == 0) return 0;
  for(ll i = 5; i*i <= n; i += 6) if(n%i == 0 or n % (i+2) == 0) return 0;
  return 1;
}

/************************************START***************************************/
const int N = 100005;

int main()
{
  ifalse;
  int n, m;
  cin >> n >> m;
  set < int > s;
  int ans = 0;
  while(m --) {
    int x;
    cin >> x;
    s.insert(x);
    int ans = 0;
    auto u = s.begin();
    if(s.size() == 1) {
      cout << n + 1, nl;
      continue;
    }
    u ++;
    int prev = 1;
    for(; u != s.end(); u ++) {
      ans += (prev + *u - 1);
      auto g = u;
      -- g;
      prev = (*g + 1);
    }
    --u;
    if(*u != n) {
      if(u == s.begin()) {
        ans += n + 1;
      }
      else {
        -- u;
        ans += n;
        ans += (*u + 1);
      }
    }
    else {
      ans += n;
      u = s.end();
      u --;
      u --;
      ans += (*u + 1);
    }
    cout << ans, nl;
  }
  return 0;
}
