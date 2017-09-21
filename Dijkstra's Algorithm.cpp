/* Using Priority Queue*/

#include <bits/stdc++.h>

using namespace std;

vector < pair < int, int > > v[1000];
int n;

void dijk(int a)
{
    priority_queue < pair < int, int >, vector < pair < int, int > >, greater < pair < int, int > > > pq;
    vector < int > dist(n, 999999999);
    bool visited[10010] = {0};

    dist[a] = 0;
    visited[a] = 1;
    pq.push({dist[a], a});

    while(!pq.empty()) {
        pair < int, int > d = pq.top();
        int u = d.second;
        visited[u] = 1;
        pq.pop();
        for(int i = 0; i < int(v[u].size()); i ++) {
            int x = v[u][i].first;
            int w = v[u][i].second;
            if(visited[x] == 0 and (dist[x] > (dist[u] + w))) {
                dist[x] = dist[u] + w;
                pq.push({dist[x], x});
            }
        }
    }
    for(int i = 0; i < n; i ++) {
        cout << i << " " << dist[i] << "\n";
    }
}

int main()
{
    cin >> n;
    int u;
    for(int i = 0; i < n; i ++) {
        int x, y, z;
        cin >> x >> y >> z;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
        if(i == 0) {
            u = x;
        }
    }
    dijk(u);
    return 0;
}
