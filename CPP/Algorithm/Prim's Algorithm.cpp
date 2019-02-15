/*input
9 14
1 2 4
2 3 8
3 4 7
4 5 9
5 6 10
6 7 2
7 8 1
8 1 8
8 2 11
8 9 7
7 9 6
9 3 2
3 6 4
4 6 14
*/

/*  Algorithm to find Minimum Cost Spanning Tree.
    Time Complexity: O(ElogV)
*/
#include <iostream>
#include <queue>
#include <vector>
#include <utility>

const int N = 100001;
const int INF = 1e9;
std::vector < std::pair < int, int > > v[N];
int n;

int prim(int src)
{
    std::priority_queue < std::pair < int, int >, std::vector < std::pair < int, int > >, std::greater < std::pair < int, int > > > pq;
    std::vector < int > edges(N, INF);
    std::vector < int > parent(N, -1);
    bool visited[N] = {0};

    edges[src] = 0;
    parent[src] = -1;
    pq.push({edges[src], src});

    while(!pq.empty()) {
        std::pair < int, int > d = pq.top();
        pq.pop();
        int u = d.second;
        visited[u] = 1;
        for(auto x : v[u]) {
            if(!visited[x.first] and (edges[x.first] > x.second)) {
                edges[x.first] = x.second;
                pq.push({edges[x.first], x.first});
                parent[x.first] = u;
            }
        }
    }
    int minCost = 0;
    for(int i = 1; i < n; i ++) {
       int w = 0;
        for(auto x : v[i]) {
            if(x.first == parent[i]) {
                w = x.second;
                break;
            }
        } 
        minCost += w;
        std::cout << i << " " << parent[i] << " " << w << "\n";
    }
    return minCost;
}

int main()
{
    int m;
    std::cin >> n >> m;
    for(int i = 0; i < m; i ++) {
        int x, y, z;
        std::cin >> x >> y >> z;
        x --, y --;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }
    std::cout << "Spanning Tree is \n";
    int minCost = prim(0);
    std::cout << "Minimum cost is " << minCost << "\n";
    return 0;
}

/*  Expected Output

    Spanning Tree is 
    1 0 4
    2 1 8
    3 2 7
    4 3 9
    5 2 4
    6 5 2
    7 6 1
    8 2 2
    Minimum cost is 37

*/