#include <iostream>
#include <vector>

const int N = 87000000;
bool mark[N];
std::vector < int > prime;

/* Implemntation of Normal Seive */
void seive()
{
    for(int i = 2; i * i <= N; i ++) {
        if(mark[i] == 0) {
            for(int j = i * 2; j < N; j += i) {
                mark[j] = 1;
            }
        }
    }
    for(int i = 2; i < N; i ++) {
        if(mark[i] == 0) {
            prime.push_back(i);
        }
    }
}

/* Simple Sieve with some optimization Avoiding all even numbers */
bool mark2[N / 2];
void optimizeSeive()
{
    prime.push_back(2);
    for(int i = 3; i * i < N; i += 2) {
        if(mark2[i / 2] == 0) {
            for(int j = i * i; j < N; j += i * 2) {
                mark2[j / 2] = 1;
            }
        }
    }
    for(int i = 3; i <= N; i +=2) {
        if(mark2[i / 2] == 0) {
            prime.push_back(i);
        }
    }
}

/* A little more optimized Seive */
void optSeive()
{
    for(int i = 2; i < N; i ++) {
        if(!mark[i]) {
            prime.push_back(i);
        }
        for(int j = 0; j < prime.size() and i * prime[j] < N; j ++) {
            mark[i * prime[j]] = 1;
            if(i % prime[j] == 0) {
                break;
            }
        }
    }
}

int main()
{
    seive();
    int n = 10;
    for(int i = 1; i < n; i ++) {
        if(not mark[i]) {
            std::cout << i << " ";
        }
    }
    return 0;
}