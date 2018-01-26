// Spoj Problem POSTERS

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t --) {
        // Indexing is like y, (x1, x2)
        vector < pair < int, pair < int, int > > > T;
        // Data structure for Sweep Status similar to T but must be ordered
        set < pair < int, pair < int, int > > > L;
        // for starting and ending events data structure should have (x, (y, (x1, x2)))
        vector < pair < int, pair < int, pair < int, int > > > > E;
        
        int n;
        cin >> n;

        // l == x1 and r == x2 and y is n - i accordingly
        for(int i = 0; i < n; i ++) {
            int l, r;
            cin >> l >> r;
            r ++;
            E.push_back({l, {n - i, {l, r}}});
            E.push_back({r, {n - i, {l, r}}});
        }

        // Sorting  E according to x axis
        sort(E.begin(), E.end());
        for(auto x: E) {
            // event is starting event
            if(x.first == x.second.second.first) {
                L.insert(x.second);
                if(x.second == *L.begin()) {
                    if(L.size() > 1) {
                        T[T.size() - 1].second.second = x.first;
                    }
                    T.push_back(x.second);
                }
            }
            // event is ending i.e, if we reach at the last point of line
            else {
                L.erase(x.second);
                if(x.second.first == T[T.size() - 1].first and L.size() > 0) {
                    T.push_back(*L.begin());
                    T[T.size() - 1].second.first = x.second.second.second;
                }
            }
        }
        int c = 0;
        bool mark[n + 10] = {0};
        for(auto x: T) {
            //cout << x.first << " " << x.second.first << " " << x.second.second << "\n";
            if(!mark[x.first] and x.second.first != x.second.second) {
                //cout << x.first << " " << x.second.first << " " << x.second.second << "\n";
                c ++;
                mark[x.first] = 1;
            }
        } 
        cout << c << "\n";
    }
    return 0;
}
