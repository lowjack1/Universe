#include <bits/stdc++.h>

using namespace std;

const int N = 1000004;
using ll = long long;

ll bit1[4 * N];
ll bit2[4 * N];

ll query(ll * ft, int index)
{
    ll sum = 0;
    for(; index > 0; index -= index & (-index)) {
        sum += ft[index];
    }
    return sum;
}

ll Rquery(int index) 
{
    return query(bit1, index) * index - query(bit2, index);
}

ll rangeQuery(int l, int r) 
{
    return Rquery(r) - Rquery(l - 1); 
}

void update(ll * ft, int index, int val, int n)
{
    for(; index <= n + 1; index += index & (-index)) {
        ft[index] += val;
    }
}

void updateRange(int l, int r, int val, int n) 
{
    update(bit1, l, val, n);
    update(bit1, r + 1, -val, n);
    update(bit2, l, val * (l - 1), n);
    update(bit2, r + 1, -val * r, n);
}

int main()
{
    int t;
    cin >> t;
    while(t --) {
        int n, c;
        cin >> n >> c;
        memset(bit1, 0, sizeof(bit1));
        memset(bit2, 0, sizeof(bit2));
        while(c --) {
            int a;
            cin >> a;
            if(a == 0) {
                int l, r;
                ll val;
                cin >> l >> r >> val;
                updateRange(l, r, val, n);
            }
            else {
                int l, r;
                cin >> l >> r;
                
                cout << rangeQuery(l, r) << "\n";
            }
        }
    }
    return 0;
}
