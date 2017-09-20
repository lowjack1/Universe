#include <bits/stdc++.h>

using namespace std;

vector < int > v[100005];
set < int > s1, s2;

void dfs(int node, int parent, int color)
{
    if(color % 2 == 1) {
        s1.insert(node);
    }
    else if(color % 2 == 0) {
        s2.insert(node);
    }
    for(auto u : v[node]) {
        if(u != parent) {
            dfs(u, node, (color + 1) % 2);
        }
    }
}

int main()
{
    int n;
    for(int i = 0; i < n - 1; i ++) {
    cin >> n;
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(1, 0, 0);
    for(auto x : s1) {
        cout << x << " ";
    }
    cout << "\n";
    for(auto y : s2) {
        cout << y << " ";
    }
    return 0;
}
