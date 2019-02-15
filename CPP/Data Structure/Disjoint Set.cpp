#include <bits/stdc++.h>

using namespace std;

class Disjoint {
    map < int, int > parent;
    map < int, int > ranks;
    public:
    //Create n disjoint Sets
    void makeSet(vector < int > universe)
    {
        for(int i: universe) {
            parent[i] = i;
            ranks[i] = 0;
        }
    }
    //Find the representative of Set
    int Find(int k)
    {
        if(parent[k] != k) {
            parent[k] = Find(parent[k]);
        }
        return parent[k];
    }
    //Union of two subsets
    void Union(int a, int b) {
        int x = Find(a);
        int y = Find(b);
        if(x == y) {
            return;
        }
        if(ranks[x] > ranks[y]) {
            parent[y] = x;
        }
        else if(ranks[x] < ranks[y]) {
            parent[x] = y;
        }
        else {
            parent[x] = y;
            ranks[y] ++;
        }
    }
};

void print(vector < int > universe, Disjoint & ds)
{
    for(int i: universe) {
        cout << ds.Find(i) << " ";
    }
    cout << "\n";
}

int main()
{
    vector < int > universe = {1, 2, 3, 4, 5};
    Disjoint ds;
    ds.makeSet(universe);
    print(universe, ds);

    ds.Union(4, 3);
    print(universe, ds);

    ds.Union(2, 1);
    print(universe, ds);

    ds.Union(1, 3);
    print(universe, ds);
    return 0;
}
