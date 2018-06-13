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
/* sub     = subtree size */
/* tree    = Centroid Tree */
/* mark[i] = centroid of ith node is known if mark[i] = 1 */

#include <bits/stdc++.h> 

using namespace std;

const int N = 10005;

vector < int > v[N];
vector < int > sub(N);
vector < int > tree[N];
bool mark[N];

/* Function for calculating the size of each subtree */
int dfs(int u, int p)
{
    sub[u] = 1;
    for(auto x: v[u]) {
        if(x != p and !mark[x]) {
            sub[u] += dfs(x, u);
        }
    }
    return sub[u];
}

/* Function to find the centroid of a tree rooted at node u and has parent p */
int centroid(int u, int p, int n)
{
    for(auto x: v[u]) {
        if(x != p and sub[x] > n / 2 and !mark[x]) {
            return centroid(x, u, n);
        } 
    }
    return u;
}

int getcentroid(int u)
{
    //sub.resize(N, 0);   
    int sz = dfs(u, -1);
    int cntroid = centroid(u, -1, sz);
    return cntroid;
}

/* Function for Centroid Decomposition */
int make(int u)
{
    int centroid_root = getcentroid(u);
    mark[centroid_root] = 1;
    for(auto x: v[centroid_root]) {
        if(!mark[x]) {
            int centroid_subtree = make(x);
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

    for(int i = 1; i < n; ++ i) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    make(0);
    
    /* Output Centroid Tree */
    for(int i = 0; i < n; i ++) {
        cout << i + 1 << " -> ";
        for(auto x: tree[i]) {
            cout << x + 1 << " ";
        }
        cout << "\n";
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
*/
