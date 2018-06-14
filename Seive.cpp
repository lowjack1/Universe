                                        /* Normal Seive */
const int NN = 87000000;
bool mark[NN];
vector < int > prime;

void seive()
{
    for(int i = 2; i * i <= NN; i ++) {
        if(mark[i] == 0) {
            for(int j = i * 2; j <= NN; j += i) {
                mark[j] = 1;
            }
        }
    }
    for(int i = 2; i <= NN; i ++) {
        if(mark[i] == 0) {
            prime.push_back(i);
        }
    }
}

=============================================================================================================================================
                            /* Simple Sieve with some optimization Avoiding all even numbers */
const int NN = 87000000;
bool mark[NN / 2];
vector < int > prime;

void seive()
{
    prime.pb(2);
    for(int i = 3; i * i < NN; i += 2) {
        if(mark[i / 2] == 0) {
            for(int j = i * i; j < NN; j += i * 2) {
                mark[j / 2] = 1;
            }
        }
    }
    for(int i = 3; i <= NN; i +=2) {
        if(mark[i / 2] == 0) {
            prime.push_back(i);
        }
    }
}

===============================================================================================================================

const int N = 87000008;
vector < int > prime;
bool mark[N];

void seive()
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
