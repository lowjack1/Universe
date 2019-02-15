/*input
4
-1 -2 -3 -4
*/

#include <bits/stdc++.h>
using namespace std;

map < string, int > mp;
vector < int > v;

/* 0 Haven't started yet
   1 In Progress
   2 Already done
*/

int func(int n, int k)
{
    if(n <= 0) {
        return 0;
    }
    if(n == 1) {
        if(k == 0 or k == 1) {
            return v[n - 1];
        }
        else {
            return 0;
        }
    }
    string s = to_string(n) + "|" + to_string(k);
    if(mp.find(s) != mp.end()) {
        return mp[s];
    }
    if(k == 0) {
        return mp[s] = max({func(n - 1, k), v[n - 1] + func(n - 1, 1), v[n - 1] + func(n - 1, 2)});
    }
    if(k == 1) {
        return mp[s] = max(v[n - 1] + func(n - 1, k), v[n - 1] + func(n - 1, 2));
    }
    if(k == 2) {
        return mp[s] = func(n - 1, k);
    }
}

int func(int n)
{
    int dp[n + 1][3];
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    dp[1][0] = dp[1][1] = dp[1][2] = v[0];
    for(int i = 2; i <= n; i ++) {
        dp[i][0] = v[i - 1];
        dp[i][1] = max({dp[i][0], v[i - 1] + dp[i - 1][1]});
        dp[i][2] = max({dp[i - 1][2], dp[i - 1][1], dp[i - 1][0]});
    }
    return max({dp[n][2], dp[n][0], dp[n][1]});
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        v.push_back(x);
    } 
    cout << func(n) << "\n";
    return 0;   
}
