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
    Time Complexity: O(ElogE)
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

std::vector < std::pair < int, std::pair < int, int > > > v;
class Disjoint {
    std::map < int, int > parent;
    std::map < int, int > rank;
public:
    void make_set(std::vector < int > &v) {
        for(int i: v) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int Find(int a) 
    {
        if(parent[a] != a) {
            parent[a] = Find(parent[a]);
        }
        return parent[a];
    }
    void Union(int a, int b) 
    {
        int x = Find(a);
        int y = Find(b);
        if(x == y) {
            return ;
        }
        if(rank[x] > rank[y]) {
            parent[y] = x; 
        }
        else if(rank[y] > rank[x]) {
            parent[x] = y;
        }
        else {
            parent[x] = y;
            rank[y] ++;
        }
    }
};

int Kruskal(int n)
{
    std::vector < int > vp;
    Disjoint ds;
    for(int i = 1; i <= n; i ++) {
        vp.push_back(i);
    }
    int mst = 0;
    ds.make_set(vp);
    for(auto x : v) {
        int u = x.second.first;
        int v = x.second.second;
        
        int set_u = ds.Find(u);
        int set_v = ds.Find(v);
        
        if(set_u != set_v) {
            std::cout << u << " " << v << "\n";
            ds.Union(set_u, set_v);
            mst += x.first;
        }
    }
    return mst;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    for(int i = 0; i < m; i ++) {
        int x, y, z;
        std::cin >> x >> y >> z;
        v.push_back({z, {x, y}});
    }
    std::sort(v.begin(), v.end());
    std::cout << "Spanning Tree is \n";
    int minCost = Kruskal(n); 
    std::cout << "Minimum cost is " << minCost << "\n";
    return 0;
}

/*  Expected Output

    Spanning Tree is 
    7 8
    6 7
    9 3
    1 2
    3 6
    3 4
    2 3
    4 5
    Minimum cost is 37
    
*/