/*input
6
3 1 2 1 4 5

output: 4
*/

 
#include<bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  int v;
  vector <int> vec;
  for (int i = 0; i < n; i++) {
    cin >> v;
    vec.push_back(v);
  }

  vector<int> last(n + 1, 0);

  int len = 1;

  last[0] = vec[0];
  
  for (int i = 1; i < n; i++) {
    if (vec[i] < last[0])
      last[0] = vec[i];
    else if (vec[i] > last[len - 1])
      last[len++] = vec[i];
    else {
      int ind = lower_bound(last.begin(), last.begin() + len, vec[i]) - last.begin();
      last[ind] = vec[i];
    }
  }
  cout << len << endl;

  return 0;
}
