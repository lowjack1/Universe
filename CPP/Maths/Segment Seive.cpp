/*input
2
2 10
3 7
*/

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int N = 65536;
bool mark[N];
vector < int > prime;
int len;

void seive()
{
    for(int i = 2; i * i <= N; i ++) {
        if(!mark[i]) {
            for(int j = 2 * i; j < N; j += i) {
                mark[j] = 1;
            }
        }
    }
    prime.push_back(2);
    for(int i = 3; i < N; i += 2) {
        if(!mark[i]) {
            prime.push_back(i);
        }
    }
}

void segmentSeive(ll l, ll r)
{
    bool mark2[r - l + 1] = {0};
    for(int i = 0; i < len and prime[i] * 1LL * prime[i] <= r; i ++) {
        int p = prime[i];
        ll s = (l / p) * p;
        while(s <= p) {
            s += p;
        }
        for(ll j = s; j <= r; j += p) {
            mark2[j - l] = 1;
        }
    }   
    for(ll i = l; i <= r; i ++) {
        if(!mark2[i - l]) {
            printf("%lld\n", i);
        }
    }
}

int main()
{
    seive();
    int t;
    len = prime.size();
    scanf("%d", &t);
    while(t --) {
        ll a, b;
        cin >> a >> b;
        segmentSeive(a, b);
    }
    return 0;
}
