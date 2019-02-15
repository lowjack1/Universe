#include <iostream>
#include <vector>
#include <set>

std::vector < int > graph[100005];
std::set < int > s1, s2;

void dfs(int node, int parent, int color)
{
    if(color % 2 == 1) {
        s1.insert(node);
    }
    else if(color % 2 == 0) {
        s2.insert(node);
    }
    for(auto u : graph[node]) {
        if(u != parent) {
            dfs(u, node, (color + 1) % 2);
        }
    }
}

int main()
{
    int n;
    std::cin >> n;
    for(int i = 1; i < n; i ++) {
        int x, y;
        std::cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int source = 1;
    int parent = 0;
    int color = 0;
    dfs(source, parent, color);
    for(auto x : s1) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    for(auto y : s2) {
        std::cout << y << " ";
    }
    return 0;
}
