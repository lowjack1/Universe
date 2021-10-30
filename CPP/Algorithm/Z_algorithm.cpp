/*input
abacaba

Output: 0 0 1 0 3 0 1
*/

#include<bits/stdc++.h>

using namespace std;

vector<int> z_function(string str) {
  int n = str.size();
  int l = 0, r = 0;
  vector <int> z(n, 0);
  for (int i = 1; i < n; i++) {
    if (i <= r)
      z[i] = min(z[i - l], r - i + 1);
    while (i + z[i] < n && str[z[i]] == str[i + z[i]])
      ++z[i];
    if (i + z[i] > r)
      l = i, r = i + z[i] - 1;
  }
  return z;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string str;
  cin >> str;
  vector<int> vec = z_function(str);
  for (auto it : vec) {
    cout << it << " ";
  }
  cout << endl;

  return 0;
}
