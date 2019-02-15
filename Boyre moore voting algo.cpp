/*  Algorithm to find majority element in an array if exist.
    Majority element in an array of size n is an element that appear more than (n / 2) times
    and hence there is atmost one such element.

    Time Complexity: O(n)
*/

#include <iostream>

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
    int n;
    std::cin >> n;
    int a[n];
    for(int i = 0; i < n; i ++) {
        std::cin >> a[i];
    }
    int d = boyremoore(a, n);
    if(d == -1) {
        std::cout << "NO";
    }
    else {
        std::cout << "YES " << d;
    }
    return 0;
}
