#include <bits/stdc++.h>

using namespace std;

vector < pair < int, int > > v[100010];

void dij(int a)
{
    priority_queue < pair < int, int >, vector < pair < int, int > >, greater < pair < int, int > > > pq;
    bool visited[10010] = {0};
    vector < int > dist(100010, 0);
    map < int, int > m;

    dist[a] = 0;
    pq.push({dist[a], a});
    m[a] = -1;
    while(!pq.empty()) {
        pair < int, int > d = pq.top();
        int u = d.second;
        pq.pop();
        visited[u] = 1;
        for(auto x : v[u]) {
            if(visited[x.first] == 0 and (dist[x.first] <= dist[u] + x.second)) {
                dist[x.first] = dist[u] + x.second;
                pq.push({dist[x.first], x.first});
                m[x.first] = u;
            }
        }
    }
    /* Printing Path */
    for(int i = 0; i < 9; i ++) {
        cout << i << " " << dist[i] << "\n";
        int d = i;
        cout << d << " ";
        while(m[d] != -1) {
            cout << m[d] << " ";
            d = m[d];
        }
        cout << "\n\n";
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i ++) {
        int x, y, z;
        cin >> x >> y >> z;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }
    dij(0);
    return 0;
}
