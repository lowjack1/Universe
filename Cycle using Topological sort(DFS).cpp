#include <bits/stdc++.h>

using namespace std;

vector < char > v[10];
bool visited[10];
map < int, int > instack;
bool flag = 0;
vector < int > order;

/* Algorithm for Detecting Cycle in a graph */

void dfs(int c, int parent)
{
    visited[c] = 1;
    instack[c] = 1;
    for(auto x : v[c]) {
        if(x != parent and visited[x] and instack[x]) {
            flag = 1; // Cycle is present
        }
        if(!visited[x]) {
            dfs(x, c);
        }
    }
    instack[c] = 0;
    order.push_back(c); // Topological sorting Order
}
