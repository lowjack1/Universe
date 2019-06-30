/*input
5
3 1
3 1 5
3 3
1 2 1
2 3 1
1 3 100
4 3
1 4 5
2 3 5
4 2 4
8 10
2 6 16
7 3 6
5 1 11
7 6 12
8 1 8
6 1 18
1 3 12
3 5 9
6 5 15
7 1 6
10 10
6 7 7
8 5 3
3 7 7
10 4 24
6 2 8
8 7 19
3 9 22
5 7 17
9 2 12
2 7 2

*/

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <math.h>
#include <iomanip>
#include <utility>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
using ll = long long;
using ld = long double;

ll MOD = 1000000007;
const int SINF = 1000000009;
const ll INF =  1000000000000000018;

#define sp          cout << " "
#define nl          cout << "\n"
#define inv(a)      powr((a), (MOD - 2))
#define all(c)      (c).begin(),(c).end()
#define rep(i,a,b)  for(ll i = (a); i < (b); i ++)
#define prec(n)     cout << fixed << setprecision(n)
#define PI          3.14159265358979323846264338327951
#define ifalse      ios_base::sync_with_stdio(false), cin.tie(NULL)

template<typename T> void toInt(string s, T &a) { istringstream(s) >> a; }
ll gcd(ll a, ll b) { ll t; while(a) { t = a; a = b%a; b = t; } return b; }
ll sub(ll a, ll b) { a -= b; a = (a + MOD) % MOD; return a; }
ll mul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
ll add(ll a, ll b) { a += b; a %= MOD; return a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }

ll powr(ll a, ll b) {
  ll x = 1LL;
  while(b) {
    if(b & 1) x = mul(x, a);
    a = mul(a, a), b >>= 1;
  }
  return x;
}

bool check(ll n)
{
  if(n == 1) return 0;
  if(n == 2 or n == 3) return 1;
  if(n%2 == 0 or n%3 == 0) return 0;
  for(ll i = 5; i*i <= n; i += 6) if(n%i == 0 or n % (i+2) == 0) return 0;
  return 1;
}

/*********************************START**********************************/
const int N = 60;
const int M = 1000000;
bool vis[N];
vector < pair < int, int > > v[N];
int n;

int dij(int a, int b)
{
  priority_queue < pair < int, int >, vector < pair < int, int > >, greater < pair < int, int > > > pq;
  bool visited[N] = {0};
  vector < int > dist(N, SINF);

  dist[a] = 0;
  pq.push({dist[a], a});
  while(!pq.empty()) {
    pair < int, int > d = pq.top();
    int u = d.second;
    pq.pop();
    visited[u] = 1;
    for(auto x : v[u]) {
      if(visited[x.first] == 0 and (dist[x.first] > dist[u] + x.second)) {
        dist[x.first] = dist[u] + x.second;
        pq.push({dist[x.first], x.first});
      }
    }
  }
  return dist[b];
}

int main()
{
  ifalse;
  int t;
  cin >> t;
  int in = 1;
  while(t --) {
    vector < pair < int, pair < int, int > > > ans;
    int m;
    cin >> n >> m;
    bool flag = 0;
    for(int i = 0; i < m; i ++) {
      int x, y, z;
      cin >> x >> y >> z;
      ans.push_back({x, {y, z}});
      v[x].push_back({y, z});
      v[y].push_back({x, z});
      vis[x] = vis[y] = 1;
    }
    for(auto x: ans) {
      int a = x.first;
      int b = x.second.first;
      int z = x.second.second;
      int d = dij(a, b);
      if(d != z) {
        flag = 1;
        break;
      }
    }
    if(flag) {
      cout << "Case #" << in << ": " << "Impossible", nl;
    } else {
      for(int i = 2; i <= n; i ++) {
        if(!vis[i]) {
          ans.push_back({1, {i, M}});
          vis[1] = 1;
          vis[i] = 1;
        }
      }
      if(!vis[1]) {
        ans.push_back({1, {n, M}});
      }
      cout << "Case #" << in << ": " << ans.size(), nl;
      for(auto x: ans) {
        cout << x.first << " " << x.second.first << " " << x.second.second, nl;
      }
    }
    in ++;
    for(int i = 1; i <= n; i ++) {
      v[i].clear();
    }
  }
  return 0;
}
