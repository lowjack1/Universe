#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
vector < pair < int, int > > v[N];
int n;

void bfs(list < int > * queue, bool * visited, int * parent)
{
    int curr = queue -> front();
    queue -> pop_front();
    for(auto x : v[curr]) {
        pair < int, int > d = x;
        if(!visited[d.first]) {
            parent[d.first] = curr;
            visited[d.first] = 1;
            queue -> push_back(d.first);
        }
    }
}

int isIntersect(bool * s_visited, bool * t_visited)
{
    for(int i = 0; i < N; i ++) {
        if(s_visited[i] and t_visited[i]) {
            return i;
        }
    }
    return -1;
}

void printpath(int * s_parent, int * t_parent, int s, int t, int intersectNode)
{
    vector < int > path;
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
    
    for(auto x : path) {
        cout << x << " ";
    }    
}

int bidirection(int s, int t)
{
    bool s_visited[N], t_visited[N];
    int s_parent[N], t_parent[N];
    int intersectNode = -1;
    
    list < int > s_queue, t_queue;
    
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
        
        intersectNode = isIntersect(s_visited, t_visited);
        
        if(intersectNode != -1) {
            printpath(s_parent, t_parent, s, t, intersectNode);
            exit(0);   
        }
    }
    return -1;
}

int main()
{
    int m;
    cin >> m;
    for(int i = 0; i < m; i ++) {
        int u, v1, w;
        cin >> u >> v1 >> w;
        v[u].push_back({v1, w});
    }
    cout << bidirection(3, 8);
    return 0;
}
