#include <bits/stdc++.h>

using namespace std;

vector < pair < int, int > > v[10000];
int n;

void prim(int a)
{
    priority_queue < pair < int, int >, vector < pair < int, int > >, greater < pair < int, int > > > pq;
    vector < int > edges(10000, 999999999);
    vector < int > parent(1000, 0);
    bool visited[10000] = {0};
    edges[a] = 0;
    parent[a] = -1;
    visited[a] = 1;
    pq.push({edges[a], a});
    while(!pq.empty()) {
        pair < int, int > d = pq.top();
        pq.pop();
        int u = d.second;
        visited[u] = 1;
        for(auto x : v[u]) {
            if(visited[x.first] == 0 and (edges[x.first] > edges[u] + x.second)) {
                edges[x.first] = edges[u] + x.second;
                pq.push({edges[x.first], x.first});
                parent[x.first] = u;
            }
        }
    }
    for(int i = 1; i < n; i ++) {
       int w = 0;
        for(auto x : v[i]) {
            if(x.first == parent[i]) {
                w = x.second;
                break;
            }
        } 
        cout << parent[i] << " " << i << " " << w << "\n";
    }
}

int main()
{
    int m;
    cin >> n >> m;
    for(int i = 0; i < m; i ++) {
        int x, y, z;
        cin >> x >> y >> z;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }
    prim(0);
    return 0;
}
