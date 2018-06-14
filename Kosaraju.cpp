vector < int > v[100004];
vector < int > v1[100004];

int vis1[100004];

stack < int > s;

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
    
    cout << s + 1, sp;
    for(auto x: v1[s]) {
        if(vis1[x] <= 1) {
            dfs1(x);
        }
    }
}


void kosaraju(int n)
{
    for(int i = 0; i < n; i ++) {
        if(!vis1[i]) {
            dfs(i);
        }
    }

    while(!s.empty()) {
        int p = s.top();
        s.pop();
        if(vis1[p] <= 1) {
            dfs1(p);
            cout << "\n";
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
        v[x].pb(y);
        v1[y].pb(x);
    }

    kosaraju(n);
    nl;    
    return 0;
}
