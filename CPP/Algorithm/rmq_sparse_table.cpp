/*input
5
2 4 8 3 6
4
0 1
0 2
1 2
2 3

*/

#include <bits/stdc++.h>

using namespace std;

#warning set N accordingly

const int N = 100001;

long long st[N][33];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  //range min query using parse table, build O(nlogn), query O(1)
  int n;
  cin >> n;
  long long v;
  vector <long long> vec;
  for (int i = 0; i < n; i++) {
    cin >> v;
    vec.push_back(v);
    st[i][0] = v;
  }
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 0; i + (1 << j) <= n; i++) {
      st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    // zero based index
    int k = log2(r - l + 1);
    long long ans = min(st[l][k], st[r - (1 << k) + 1][k]);
    cout << ans << endl;
  }

  return 0;
}