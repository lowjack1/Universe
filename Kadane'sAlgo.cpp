/* For Maximum Sum in subarray */

#include <bits/stdc++.h>

using namespace std;

int n;
vector < int > v;

int kadane()
{
    int maxSum = v[0];
    int maxx = v[0];
    for(int i = 1; i < n; i ++) {
        maxSum = max(v[i], maxSum + v[i]);
        maxx = max(maxx, maxSum);
    }
    return maxx;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << kadane() << "\n";
    return 0;
}
