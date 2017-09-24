#include <bits/stdc++.h>

using namespace std;

vector < pair < int, pair < int, int > > > v;
class Disjoint {
    map < int, int > parent;
    map < int, int > rank;
public:
    void make_set(vector < int > &v) {
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
    vector < int > vp;
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
            cout << u << " " << v << "\n";
            ds.Union(set_u, set_v);
            mst += x.first;
        }
    }
    return mst;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i ++) {
        int x, y, z;
        cin >> x >> y >> z;
        v.push_back({z, {x, y}});
    }
    sort(v.begin(), v.end());
    cout << Kruskal(n) << "\n";
    return 0;
}
