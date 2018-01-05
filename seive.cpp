#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int N = 87000008;

ll mark[N];
ll prime[N];

void seive()
{
    int o = 0;
    for(int i = 2; i * i <= 87000000; i ++) {
        if(mark[i] == 0) {
            for(int j = i * 2; j <= 87000000; j += i) {
                mark[j] = -1;
            }
        }
    }
    for(int i = 2; i <= 87000000; i ++) {
        if(mark[i] == 0) {
            prime[o ++] = i;
        }
    }
}

int main() 
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    seive();
    int t;
    cin >> t;
    while(t --) {
        int n;
        cin >> n;
        cout << prime[n - 1] << "\n";
    }
    return 0;
}
