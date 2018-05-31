vector < int > v[10004];
vector < int > v1[10004];

int vis1[10004];
int vis2[10004];

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
    vis2[s] =  1;
    cout << s + 1 << " ";
    for(auto x: v1[s]) {
        if(!vis2[x]) {
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

    for(int i = 0; i < n; i ++) {
        for(auto x: v[i]) {
            v1[x].pb(i);
        }
    }

    while(!s.empty()) {
        int p = s.top();
        s.pop();
        if(!vis2[p]) {
            dfs1(p);
            nl;
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
    }

    kosaraju(n);
    nl;    
    return 0;
}
