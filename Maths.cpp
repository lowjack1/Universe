//calculating euler phi function

const int N = 1e6 + 5;
int phi[N];

void cal()
{
    for(int i = 1; i < N; i ++) {
        phi[i] = i;
    }
    for(int i = 2; i < N; i ++) {
        if(phi[i] == i) {
            for(int j = i; j < N; j += i) {
                phi[i] /= i;
                phi[i] *= (i - 1);
            }
        }
    }
}

// calculating prime factors of a range

int mn[N]; // store smallest prime divisior of i
vector < int > prime;
vector < int > divisor[N]; // store prime divisor of i

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
