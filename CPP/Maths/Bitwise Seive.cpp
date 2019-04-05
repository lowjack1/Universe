/*
    Bitwise Seive
*/


/*input
2
2 10
3 7
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;

const int N = 33554432;

ll mark[N / 64];
vector < ll > prime;

bool ifComposite(ll n)
{
    return (mark[n / 64] & (1 << ((n >> 1) & 31)));
}

bool makeComposite(ll n)
{
    mark[n / 64] |= (1 << ((n >> 1) & 31));
}

void seive()
{
    for(ll i = 3; i * i <= N; i += 2) {
        if(!ifComposite(i)) {
            for(ll j = i * i; j < N; j += 2 * i) {
                makeComposite(j);
            }
        }
    }
    prime.push_back(2);
    for(int i = 3; i < N; i += 2) {
        if(!ifComposite(i)) {
            prime.push_back(i);
        }
    }
}

bool isPrime(ll n)
{
    for(int i = 0; i < prime.size() and prime[i] * prime[i] <= n; i ++) {
        if(n % prime[i] == 0) {
            return 0;
        }
    }
    return 1;
}
int main()
{
    seive();
    int t;
    scanf("%d", &t);
    int len = prime.size();
    while(t --) {
        ll a, b;
        cin >> a >> b;
        int n1 = lower_bound(prime.begin(), prime.end(), a) - prime.begin();
        if(n1 == len) {
            if(a % 2 == 0) {
                a ++;
            }
            for(ll i = a; i <= b; i ++) {
                if(isPrime(i)) {
                    printf("%lld\n", i);
                }
            }
        }
        else {
            bool flag = 0;
            for(int i = n1; i < len; i ++) {
                if(prime[i] <= b) {
                    printf("%lld\n", prime[i]);
                }
                else {
                    flag = 1;
                    break;
                }
            }
            if(!flag) {
                a = prime[len - 1] + 2;
                for(ll i = a; i <= b; i += 2) {
                    if(isPrime(i)) {
                        printf("%lld\n", i);
                    } 
                }
            }
        }
    }
    return 0;
}
