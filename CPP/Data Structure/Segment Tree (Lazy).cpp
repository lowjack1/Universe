#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;
using ll = long long ;

ll tree[4 * N];
ll lazy[4 * N];

void make(int low, int high, int pos)
{
    if(low == high) {
        tree[pos] = 0;
        return ;
    }
    int mid = low + (high - low) / 2;
    make(low, mid, 2 * pos + 1);
    make(mid + 1, high, 2 * pos + 2);
    tree[pos] = tree[2 * pos + 1] + tree[2 * pos + 2];
}

void update(int low, int high, int l, int r, ll val, int pos)
{
    if(low > high) {
        return ;
    }
    // Make sure all propagation is done at pos. If not update tree at pos and mark children for lazy propagation
    if(lazy[pos] != 0) {
        tree[pos] += (high - low + 1) * lazy[pos];
        if(low != high) {
            lazy[2 * pos + 1] += lazy[pos];
            lazy[2 * pos + 2] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    // NO Overlap
    if(l > high or r < low) {
        return ;
    }
    // Totally Overlap
    if(l <= low and high <= r) {
        tree[pos] += (high - low + 1) * val;
        if(low != high) {
            lazy[2 * pos + 1] += val;
            lazy[2 * pos + 2] += val;
        }
        return ;
    }
    // Partially Overlap
    int mid = low + (high - low) / 2;
    update(low, mid, l, r, val, 2 * pos + 1);
    update(mid + 1, high, l, r, val, 2 * pos + 2);
    tree[pos] = tree[2 * pos + 1] + tree[2 * pos + 2];
}

ll query(int low, int high, int l, int r, int pos) 
{
    if(low > high) {
        return 0;
    }
    if(lazy[pos] != 0) {
        tree[pos] += (high - low + 1) * lazy[pos];
        if(low != high) {
            lazy[2 * pos + 1] += lazy[pos];
            lazy[2 * pos + 2] += lazy[pos];
        } 
        lazy[pos] = 0;
    }
    if(l > high or r < low) {
        return 0;
    }
    if(l <= low and high <= r) {
        return tree[pos];
    }
    int mid = low + (high - low) / 2;
    return query(low, mid, l, r, 2 * pos + 1) + query(mid + 1, high, l, r, 2 * pos + 2);
}

int main()
{
	int t;
	cin >> t;
	while(t --) {
		int n, c;
		cin >> n >> c;
		memset(lazy, 0, sizeof(lazy));
		memset(tree, 0, sizeof(tree));
		make(0, n - 1, 0);
		while(c --) {
			int aa, l, r;
			cin >> aa >> l >> r;
			if(aa == 0) {
				ll val;
				cin >> val;
				update(0, n - 1, l - 1, r - 1, val, 0);
			}
			else {
				cout << query(0, n - 1, l - 1, r - 1, 0);
				cout << "\n";
			}
		}
	}
    return 0;
}
