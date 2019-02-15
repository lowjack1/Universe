/*input
10 4
1 5 2 4 6 1 3 5 7 10
1 3 8
1 1 6
2 8 0
1 8 8
*/

#include <bits/stdc++.h>

using namespace std;

vector < int > v;
vector < int > block;
int block_size;

void make(vector < int > v, int n) 
{
    block_size = sqrt(n);
    int sum = 0;
    for(int i = 0; i < n; i ++) {
        sum += v[i];
        if((i + 1) % block_size == 0) {
            block.push_back(sum);
            sum = 0;
        }
    }
    block.push_back(sum);
}

void update(int index, int val) 
{
    int block_no = index / block_size;
    block[block_no] += val - v[index];
    v[index] = val;
}

int query(int l, int r)
{
    int result = 0;
    while(l <= r and l % block_size != 0 and l != 0) {
        result += v[l ++];
    }
    while(l + block_size <= r) {
        result += block[l / block_size];
        l += block_size;
    } 
    while(l <= r) {
        result += v[l ++];
    }
    return result;
} 

int main()
{
    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    make(v, n);
    while(q --) {
        int a;
        cin >> a;
        if(a == 1) {
            int l, r;
            cin >> l >> r;
            cout << query(l, r) << "\n";
        }
        else {
            int in, val;
            cin >> in >> val;
            update(in, val);
        }
    }
    return 0;
}
