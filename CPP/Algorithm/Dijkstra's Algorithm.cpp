/*input
9 14
0 1 4
0 7 8
1 2 8
1 7 11
7 8 7
7 6 1
2 8 2
8 6 6
6 5 2
2 5 4
2 3 7
3 5 14
3 4 9
4 5 10
*/

/*  Algorithm to find shortest distance from source to all vertices.
    Time Complexity O(ElogV)

*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <utility>

std::vector < std::pair < int, int > > v[100010];
const int N = 1e9;
int n;

void dij(int a)
{
    std::priority_queue < std::pair < int, int >, std::vector < std::pair < int, int > >, std::greater < std::pair < int, int > > > pq;
    bool visited[10010] = {0};
    std::vector < int > dist(100010, N);
    std::map < int, int > m;

    dist[a] = 0;
    pq.push({dist[a], a});
    m[a] = -1;
    while(!pq.empty()) {
        std::pair < int, int > d = pq.top();
        int u = d.second;
        pq.pop();
        visited[u] = 1;
        for(auto x : v[u]) {
            if(visited[x.first] == 0 and (dist[x.first] >= dist[u] + x.second)) {
                dist[x.first] = dist[u] + x.second;
                pq.push({dist[x.first], x.first});
                m[x.first] = u;
            }
        }
    }
    /* Printing Path */
    for(int i = 0; i < n; i ++) {
        std::cout << i << " " << dist[i] << "\n";
        int d = i;
        std::cout << d << " ";
        while(m[d] != -1) {
            std::cout << m[d] << " ";
            d = m[d];
        }
        std::cout << "\n\n";
    }
}

int main()
{
    int m;
    std::cin >> n >> m;
    for(int i = 0; i < m; i ++) {
        int x, y, z;
        std::cin >> x >> y >> z;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }
    dij(0);
    return 0;
}


/* Expected Output
    0 0
    0 

    1 4
    1 0 

    2 12
    2 1 0 

    3 19
    3 2 1 0 

    4 21
    4 5 6 7 0 

    5 11
    5 6 7 0 

    6 9
    6 7 0 

    7 8
    7 0 

    8 14
    8 2 1 0 
*/
