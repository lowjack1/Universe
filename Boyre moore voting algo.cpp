#include <bits/stdc++.h>

using namespace std;

int boyremoore(int a[], int n)
{
    int max_index = 0, count = 1, max_value = 0;
    for(int i = 1; i < n; i ++) {
        if(a[max_index] == a[i]) {
            count ++;
        } 
        else {
            count --;
        }
        if(count == 0) {
            max_index = i;
            count = 1;
        }
    }
    max_value = a[max_index];
    count = 0;
    for(int i = 0; i < n; i ++) {
        if(a[i] == max_value) {
            count ++;
        }
    }
    if(count > n / 2) {
        return max_value;
    }
    else {
        return -1;
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t --) {
        int n;
        cin >> n;
        int a[n];
        
        for(int i = 0; i < n; i ++) {
            cin >> a[i];
        }
        int d = boyremoore(a, n);
        if(d == -1) {
            cout << "NO";
        }
        else {
            cout << "YES " << d;
        }
        cout << "\n";
    }
    return 0;
}
