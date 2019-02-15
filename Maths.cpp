#include <iostream>
#include <vector>
#include <string.h>

/* calculating euler phi function */

const int N = 1e5;
int phi[N];

void cal()
{
    for(int i = 1; i < N; i ++) {
        phi[i] = i;
    }
    for(int i = 2; i < N; i ++) {
        if(phi[i] == i) {
            for(int j = i; j < N; j += i) {
                phi[j] /= i;
                phi[j] *= (i - 1);
            }
        }
    }
}

/* calculating prime factors of a range */

int mn[N];  // store smallest prime divisior of i
std::vector < int > prime;
std::vector < int > divisor[N];  // store prime divisor of i

void seive()
{
    memset(mn, -1, sizeof(mn));
    for(int i = 2; i < N; i ++) {
        if(mn[i] ==  -1) {
            prime.push_back(i);
            for(int j = i; j < N; j += i) {
                if(mn[j] == -1) {
                    mn[j] = i;
                }
            }
        }
    }
}

void calculate(int a, int b) // calculating prime divisor of all number in a given range 
{
    for(int i = a; i <= b; i ++) {
        int x = i;
        while(x > 1) {
            int d = mn[x]; // smallest prime divisior of x
            while(x % d == 0) {
                x /= d;
            }       
            divisor[i].push_back(d);      
        }
    }
}

// Mobius Function
int mu[N];
std::vector < int > divs[N];

void init()
{
    for(int i = 1; i < N; i ++) {
        divs[i].push_back(1);
    }
    for(int i = 2; i < N; i ++) {
        for(int j = i; j < N; j += i) {
            divs[j].push_back(i);
        }
    }
    mu[1] = 1;
    for(int i = 2; i < N; i ++) {
        if(divs[i].size() == 2) {
            mu[i] = -1;
        }
        else {
            int p = divs[i][1]; // smallest prime divisior
            if((i / p) % p == 0) {
                mu[i] = 0;
            }
            else {
                mu[i] = mu[i / p] * -1;
            }
        }
    }
}

int main()
{
    cal();
    seive();
    init();
    int n = 28;
    std::cout << "Euler Phi function of " << n << " is " << phi[n] << "\n";
    std::cout << "Mobius function of " << n << " is " << mu[n] << "\n"; 
    return 0;
}