#include <bits/stdc++.h>

using namespace std;

vector < int > v[1000];
bool visited[1000];

void dfs(int s)
{
    visited[s] = 1;
    for(auto x : v[s]) {
        if(!visited[x]) {
            dfs(x);
        }
    }
}

bool connected(int n)
{
    memset(visited, 0, sizeof(visited));
    
    // Find a vertex with a non zero degree
    int i;
    for(i = 1; i <= n; i ++) {
        if(v[i].size() > 0) {
            break;
        }
    }
    
    // If there are non zero edge in the graph return true
    if(i == n) {
        return 1;
    }
    
    dfs(i);
    // Check if all non zero degree are visited;=
    for(int i = 1; i <= n; i ++) {
        if(visited[i] == 0 and v[i].size() > 0) {
            return 0;
        }
    }
    return 1;
}

// Check For Euler path

int euler(int n)
{
    if(connected(n) == 0) {
        return 0;
    }
    int odd;
    for(int i = 1; i <= n; i ++) {
        if(v[i].size() & 1) {
            odd ++;
        }
    }
    return (odd) ? 1 : 2;
}

int main()
{
    int m, n;
    cin >> n >> m;
    
    for(int i = 0; i < n ; i ++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    int d = euler(n);
    if(d == 0) {
        cout << "No eulerian path ";
    }
    else if(d == 1) {
        cout << "Eulerian Path but no eulerian cycle";
    }
    else {
        cout << "Eulerian Cycle";
    }
    return 0;
}
