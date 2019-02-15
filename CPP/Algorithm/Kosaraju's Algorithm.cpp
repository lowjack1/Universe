/*input
5 5
2 1
1 3
3 2
1 4
4 5
*/

/*  Algorithm to Find all strongly connected components of a directed graph
    Time Complexity: O(V+E)
*/

#include <iostream>
#include <vector>
#include <stack>

const int N = 100001;

std::vector < int > v[N];
std::vector < int > v1[N];

int vis1[N];

std::stack < int > s;

void dfs(int s1) {
    vis1[s1] =  1;
    for(auto x: v[s1]) {
        if(!vis1[x]) {
            dfs(x);
        }
    }
    s.push(s1);
}

void dfs1(int s) {
    vis1[s] = 2;
    
    std::cout << s << " ";
    for(auto x: v1[s]) {
        if(vis1[x] <= 1) {
            dfs1(x);
        }
    }
}


void kosaraju(int n)
{
    for(int i = 1; i <= n; i ++) {
        if(!vis1[i]) {
            dfs(i);
        }
    }

    while(!s.empty()) {
        int p = s.top();
        s.pop();
        if(vis1[p] <= 1) {
            dfs1(p);
            std::cout << "\n";
        }
    }
}

int main ()
{
    int n, m;
    std::cin >> n >> m;
    
    for(int i = 0; i < m; i ++) {
        int x, y;
        std::cin >> x >> y;
        v[x].push_back(y);
        v1[y].push_back(x);
    }
    std::cout << "Components are \n";
    kosaraju(n);
    return 0;
}

/*  Expected Output
    
    Components are 
    1 2 3 
    4 
    5 
*/