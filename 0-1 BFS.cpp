/*input
9 14
0 1 0
0 7 1
1 7 1
1 2 1
2 8 1
8 7 1
8 6 1
7 6 1
2 3 0
2 5 0
6 5 1
3 5 1
3 4 1
4 5 1
*/

#include <bits/stdc++.h>
 
using namespace std;

const int inf = 1e9;
vector < pair < int, int > > v[10000];

void bfs(int n, int source)
{
    int dist[n + 1];
    for(int i = 0; i <= n; i ++) {
        dist[i] = inf;
    }
    dist[source] = 0;
    bool visited[n + 1] = {0};

    deque < pair < int, int > > dq;
    dq.push_front({source, 0});
    
    while(!dq.empty()) {
        pair < int, int > p = dq.front();
        dq.pop_front();
        visited[p.first] = 1;
        for(auto x: v[p.first]) {
            dist[x.first] = min(dist[x.first], dist[p.first] + x.second);
            if(not visited[x.first]) {
                if(x.second == 0) dq.push_front(x);
                else if(x.second == 1) dq.push_back(x);
            }
        }
    }

    for(int i = 0; i < n; i ++) {
        cout << dist[i] << " ";
    }
}
int main ()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i ++ ) {
        int x, y, w;
        cin >> x >> y >> w;
        v[x].push_back({y, w});
        v[y].push_back({x, w});
    }

    bfs(n, 0);
    cout << "\n";
    return 0;
}

/* Expected Output

    0 0 1 1 2 1 2 1 2 

*/
