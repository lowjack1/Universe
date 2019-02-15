/*input
5 6
1 2 
2 3
3 4
4 5
1 4
3 5
3 5
*/

/* Bidirectional Search is used to find the shortest path between two vertices
   It is bidirectional because it starts searching path from both direction i.e 
   from source vertex and destination vertex.

   Time Complexity: O(b^(d / 2))
   b = Branching factor (No of child)
   d = Distance between source and destination vertex.
*/

#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string.h>

const int N = 100005;
std::vector < int > graph[N];

void bfs(std::list < int > * queue, bool * visited, int * parent)
{
    int curr = queue -> front();
    queue -> pop_front();
    for(auto vertex: graph[curr]) {
        if(!visited[vertex]) {
            parent[vertex] = curr;
            visited[vertex] = 1;
            queue -> push_back(vertex);
        }
    }
}

int isIntersect(int vertices, bool * s_visited, bool * t_visited)
{
    for(int i = 0; i <= vertices; i ++) {
        if(s_visited[i] and t_visited[i]) {
            return i;
        }
    }
    return -1;
}

void printpath(int * s_parent, int * t_parent, int s, int t, int intersectNode)
{
    std::vector < int > path;
    path.push_back(intersectNode);
    
    int i = intersectNode;
    while(i != s) {
        path.push_back(s_parent[i]);
        i = s_parent[i];
    }
    
    reverse(path.begin(), path.end());
    
    i = intersectNode;
    while(i != t) {
        path.push_back(t_parent[i]);
        i = t_parent[i];
    }
    
    for(auto x: path) {
        std::cout << x << " ";
    }
}

int bidirection(int vertices, int s, int t)
{
    bool s_visited[vertices + 1], t_visited[vertices + 1];
    int s_parent[vertices + 1], t_parent[vertices + 1];
    int intersectNode = -1;
    
    std::list < int > s_queue, t_queue;
    
    memset(s_visited, 0, sizeof(s_visited));
    memset(t_visited, 0, sizeof(t_visited));
    
    s_queue.push_back(s);
    s_visited[s] = 1;
    s_parent[s] = -1;

    t_queue.push_back(t);
    t_visited[t] = 1;
    t_parent[t] = -1;
    
    while(!s_queue.empty() and !t_queue.empty()){
        bfs(&s_queue, s_visited, s_parent);
        bfs(&t_queue, t_visited, t_parent);
        
        intersectNode = isIntersect(vertices, s_visited, t_visited);
        
        if(intersectNode != -1) {
            printpath(s_parent, t_parent, s, t, intersectNode);
            exit(0);   
        }
    }
    return -1;
}

int main()
{
    int vertices, edges, source, destination;
    std::cin >> vertices >> edges;
    for(int i = 0; i < edges; i ++) {
        int u, v1;
        std::cin >> u >> v1;
        graph[u].push_back(v1);
    }
    std::cin >> source >> destination;
    std::cout << bidirection(vertices, source, destination);
    return 0;
}

/* Expected Output
    
    3 5
*/