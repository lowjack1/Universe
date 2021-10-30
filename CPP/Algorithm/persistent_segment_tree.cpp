/*input
10
1 2 3 4 5 6 7 8 9 10 
6
2 0 1 6
1 0 10 30
1 1 2 10
1 2 3 10
2 3 2 3
2 1 1 10
 
*/

#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int LOG_N = log2(N) + 1;

int seg[4 * LOG_N * N], lc[4 * LOG_N * N], rc[4 * LOG_N * N], root[N];
int id = 0;

int build(int low, int high) {
  int node = id++;
  if (low == high) {
    return node;
  }

  int mid = (low + high) >> 1;

  lc[node] = build(low, mid);
  rc[node] = build(mid + 1, high);

  return node;
}

int update(int prev, int low, int high, int pos, int value) {
  int node = id++;
  if (low == high) {
    seg[node] = value;
    return node;
  }

  lc[node] = lc[prev];
  rc[node] = rc[prev];

  int mid = (low + high) >> 1;

  if (pos <= mid) {
    lc[node] = update(lc[prev], low, mid, pos, value);
  } else {
    rc[node] = update(rc[prev], mid + 1, high, pos, value);
  }

  seg[node] = seg[lc[node]] + seg[rc[node]];

  return node;
}

int query(int root, int low, int high, int l, int r) {
  if (low > r || high < l) return 0;
  if (low >= l && high <= r) return seg[root];
 
  int mid = (low + high) >> 1;
 
  return query(lc[root], low, mid, l, r) + query(rc[root], mid + 1, high, l, r);
}

void persistentSegTree(int n) {
  root[0] = build(0, n - 1);
}

 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  vector<int> vec;
  int v;
  for (int i = 0; i < n; i++) {
    cin >> v;
    vec.push_back(v);
  }
  
  int q;
  cin >> q;

  persistentSegTree(n);

  for (int i = 0; i < n; i++) {
    root[0] = update(root[0], 0, n - 1, i, vec[i]);
  }
 
  int first_type = 1;
 
  while (q--) {
    int type;
    cin >> type;
 
    if (type == 1) {
      int idx, pos, v;
      cin >> idx >> pos >> v;
      pos--;
      v += query(root[idx], 0, n - 1, pos, pos);
      root[first_type++] = update(root[idx], 0, n - 1, pos, v);
    } else {
      int idx, l, r;
      cin >> idx >> l >> r;
      l--, r--;
      int ans = query(root[idx], 0, n - 1, l, r);
      cout << ans << endl;
    }
  }
 
  return 0;
}

