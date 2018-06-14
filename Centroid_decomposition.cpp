/*input
15   
15 14
14 11
11 9
11 13
9 6
6 3
3 4
3 2
3 5
2 1
5 7
5 8
7 10
10 12
*/

/* Centroid Decomposition or Seperator Decomposition */
/* sub    = subtree size */
/* tree   = Centroid Tree */
/* par[i] = parent of ith node in centroid tree */

#include <bits/stdc++.h> 

using namespace std;

const int N = 10005;

vector < int > v[N];
vector < int > sub(N);
vector < int > tree[N];
int par[N];

/* Function for calculating the size of each subtree */
int dfs(int u, int p)
{
    sub[u] = 1;
    for(auto x: v[u]) {
        if(x != p and par[x] == -1) {
            sub[u] += dfs(x, u);
        }
    }
    return sub[u];
}

/* Function to find the centroid of a tree rooted at node u and has parent p */
int centroid(int u, int p, int n)
{
    for(auto x: v[u]) {
        if(x != p and sub[x] > n / 2 and par[x] == -1) {
            return centroid(x, u, n);
        } 
    }
    return u;
}

int getcentroid(int u, int p)
{
    //sub.resize(N, 0);   
    int sz = dfs(u, p);
    int cntroid = centroid(u, p, sz);
    return cntroid;
}

/* Function for Centroid Decomposition */
int make(int u, int p)
{
    int centroid_root = getcentroid(u, p);
    if(p == -1) {
        p = centroid_root;
    }
    par[centroid_root] = p;
    for(auto x: v[centroid_root]) {
        if(par[x] == -1) {
            int centroid_subtree = make(x, centroid_root);
            tree[centroid_root].push_back(centroid_subtree);
            tree[centroid_subtree].push_back(centroid_root);
        }
    }
    return centroid_root;
}

int main()
{
    int n;
    cin >> n;
    memset(par, -1, sizeof(par));
    for(int i = 1; i < n; ++ i) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    make(0, -1);
    
    /* Output Centroid Tree */
    for(int i = 0; i < n; i ++) {
        cout << i + 1 << " -> ";
        for(auto x: tree[i]) {
            cout << x + 1 << " ";
        }
        cout << "\n";
    } 

    for(int i = 0; i < n; i ++) {
        cout << par[i] + 1 << " ";
    }
    return 0;
}

/* Expected Output 
    1 -> 2 
    2 -> 1 3 
    3 -> 11 4 2 7 
    4 -> 3 
    5 -> 8 7 
    6 -> 9 
    7 -> 5 10 3 
    8 -> 5 
    9 -> 6 11 
    10 -> 12 7 
    11 -> 14 9 13 3 
    12 -> 10 
    13 -> 11 
    14 -> 15 11 
    15 -> 14 
    2 3 3 3 7 9 3 5 11 7 3 10 11 11 14  
*/
