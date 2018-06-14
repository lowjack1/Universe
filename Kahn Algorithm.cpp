vector < int > v[10005];
map < int, int > indegree;

void kahn(int n) 
{
    queue < int > q;
    for(int i = 0; i < n; i ++) {
        if(mp[i] == 0) {
            q.push(i);
        }
    }
    nl;
    while(!q.empty()) {
        int d = q.front();
        q.pop();
        cout << d + 1 << " ";
        for(auto x: v[d]) {
            indegree[x] --;
            if(indegree[x] == 0) {
                q.push(x);
            }
        }
    }
}

int main ()
{
    fast;
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        v[x].push_back(y);
        indegree[y] ++;
    }

    kahn(n);    
    
    return 0;
}
