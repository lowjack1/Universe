/*input
4 5
1 3
2 3
3 4
3 5
4 5
*/

/*  Detect Cycle in  directed or undirected graph using topological sorting 
    Time Complexity: O(V + E)
*/

#include <iostream>
#include <vector>
#include <stack>
const int N = 100001;

std::vector < int > graph[N];
std::stack < int > order;
bool visited[N];
bool instack[N];
bool flag;

/* Algorithm for Detecting Cycle in a graph */

void dfs(int c, int parent)
{
    visited[c] = 1;
    instack[c] = 1;
    for(auto x : graph[c]) {
        if(x != parent and visited[x] and instack[x]) {
            flag = 1; // Cycle is present
        }
        if(!visited[x]) {
            dfs(x, c);
        }
    }
    instack[c] = 0;
    order.push(c); // Topological sorting Order
}

int main()
{
    int vertices, edges;
    std::cin >> vertices >> edges;
    for(int i = 0; i < edges; i ++) {
        int x, y;
        std::cin >> x >> y;
        graph[x].push_back(y);
        // graph[y].push_back(x); // Uncomment this line to make graph undirected
    }
    for(int i = 1; i <= vertices; i ++) {
        if(not visited[i]) dfs(i, 0);
    }
    if(flag) {
        std::cout << "Cycle is Present";
    }
    else {
        std::cout << "Topologically Sorted order is \n";
        while(!order.empty()) {
            std::cout << order.top() << " ";
            order.pop();
        }
    }
    return 0;
}