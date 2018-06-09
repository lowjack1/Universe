// INcompleted

#include <bits/stdc++.h>

using namespace std;

int n, m;
bool a[500][500];
vector < int > v[10000];

int create_edge()
{
    /*
    * Making edge in all four direction using this matrix e.g., (1 can make edge with 2 and 4) and (5 can make edge with 2, 4, 6, 8) 
    * for n = 3 and m = 3
        | 1 | 2 | 3 | 
        | 4 | 5 | 6 |
        | 7 | 8 | 9 |
    */
    int k = 1;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            /* If last row then add edge on the right side */
            if(i == n) {
                /* If not bottom right cell */
                if(j != m) {
                    v[k].push_back(k + 1);
                    v[k + 1].push_back(k);
                }
            }
            /* If last column then add edge toward  down */
            else if(j == m) {
                v[k].push_back(k + m);
                v[k + m].push_back(k);
            }
            else {
                /* Add edge in all four direction */
                v[k].push_back(k + 1);
                v[k + 1].push_back(k);
                v[k].push_back(k + m);
                v[k + m].push_back(k);
            }
            k ++;
        }
    }   
    return k;
}

int main()
{
    int t;
    cin >> t;
    while(t --) {
        string s;
        cin >> n >> m;
        
        memset(a, 0, sizeof(a));
        
        int k = create_edge();
        
        for(int i = 0; i < m; i ++) {
            cin >> s;
            for(int j = 0; j < m; j ++) {
                a[i][j] = (s[j] - '0'); 
            }
        }
        
        for(int i = 0; i < k; i ++) {
            v[i].clear();
        }
    }
    return 0;
}
