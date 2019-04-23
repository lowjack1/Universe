/*
  Time Complexity  = O(logn * loglongn)
  Space Complexity = O(logn)
*/

/*input
10
*/

#include <iostream>
#include <map>

using namespace std;

using ll = long long;
 
ll add(ll x, ll y, ll MOD) { x += y; x %= MOD; return x; }
ll sub(ll x, ll y, ll MOD) { x -= y; x = (x + MOD) % MOD; return x; }
ll mul(ll x, ll y, ll MOD) { return ((x % MOD) * (y % MOD)) % MOD; }

const ll MOD = 1000000007;

map < ll, ll > fib;

ll fibonacci(ll n)
{
  if(fib.find(n) != fib.end()) {
    return fib[n];
  }
  ll k = n / 2;
  ll res = 0;
  if(!(n&1)) {
    // f(k) * f(k) + f(k - 1) * f(k - 1);
    res = add(mul(fibonacci(k), fibonacci(k), MOD), mul(fibonacci(k - 1), fibonacci(k - 1), MOD), MOD);
  }
  else {
    // f(k) * f(k + 1) + f(k - 1) * f(k)
    res = add(mul(fibonacci(k), fibonacci(k + 1), MOD), mul(fibonacci(k - 1), fibonacci(k), MOD), MOD);
  }
  return fib[n] = res;
}

int main()
{
  ll n;
  cin >> n;
  fib[-1] = 0;
  fib[0] = fib[1] = 1;
  cout << fibonacci(n - 1) << "\n";
  return 0;
}
