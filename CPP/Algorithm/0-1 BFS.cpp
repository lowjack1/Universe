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


/*  0-1 BFS is nothing but a special case of Dijkstra’s Algorithm which can only be 
    applied on Graph with vertices weighted 0 and x(x>=0) only.

    Time complexity: O(E + V).
*/

#include <iostream>
#include <vector>
#include <utility>
#include <queue>

const int INF = 1e9;
std :: vector < std :: pair < int, int > > graph[10000];

void bfs(int vertices, int source)
{
    int dist[vertices + 1];
    for(int i = 0; i <= vertices; i ++) {
        dist[i] = INF;
    }
    dist[source] = 0;

    std :: deque < std :: pair < int, int > > dq;
    dq.push_front({source, 0});
    
    while(!dq.empty()) {
        std :: pair < int, int > src = dq.front();
        dq.pop_front();
        for(auto vertex: graph[src.first]) {
            if(dist[vertex.first] > dist[src.first] + vertex.second) {
                dist[vertex.first] = dist[src.first] + vertex.second;
                dq.push_front(vertex);
            }
        }
    }

    for(int i = 0; i < vertices; i ++) {
        std :: cout << "Distance from " << source << " to " << i << " is " << dist[i] << "\n";
    }
}

int main ()
{
    int vertices, edges;
    std :: cin >> vertices >> edges;

    for(int i = 0; i < edges; i ++) {
        int vertex1, vertex2, weight;
        std :: cin >> vertex1 >> vertex2 >> weight;
        graph[vertex1].push_back({vertex2, weight});
        graph[vertex2].push_back({vertex1, weight});
    }
    int source = 0;
    bfs(vertices, source);
    std :: cout << "\n";
    return 0;
}

/* Expected Output

    Distance from 0 to 0 is 0
    Distance from 0 to 1 is 0
    Distance from 0 to 2 is 1
    Distance from 0 to 3 is 1
    Distance from 0 to 4 is 2
    Distance from 0 to 5 is 1
    Distance from 0 to 6 is 2
    Distance from 0 to 7 is 1
    Distance from 0 to 8 is 2

*/
