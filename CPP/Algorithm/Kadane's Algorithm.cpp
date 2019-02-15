/*input
4
1 2 -1 10
*/

/*  Algorithm to find mmaximum sum contigiuous subarray
    Time Complexity: O(n)
*/

#include <iostream>
#include <vector>

using namespace std;

int n;
std::vector < int > v;

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
    std::cin >> n;
    for(int i = 0; i < n; i ++) {
        int x;
        std::cin >> x;
        v.push_back(x);
    }

    std::cout << kadane() << "\n";
    return 0;
}

/* Expected Output 
   12
*/