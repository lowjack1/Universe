                                        /* Normal Seive */
const int N = 87000000;
bool mark[N];
int prime[N];

void seive()
{
    int o = 0;
    for(int i = 2; i * i <= 87000000; i ++) {
        if(mark[i] == 0) {
            for(int j = i * 2; j <= 87000000; j += i) {
                mark[j] = 1;
            }
        }
    }
    for(int i = 2; i <= 87000000; i ++) {
        if(mark[i] == 0) {
            prime[o ++] = i;
        }
    }
}

=============================================================================================================================================
                            /* Simple Sieve with some optimization Avoiding all even numbers */
bool mark[N / 2];
int prime[N];

void seive()
{
    int o = 0;
    prime[o ++] = 2;
    for(int i = 3; i * i < 87000000; i += 2) {
        if(mark[i / 2] == 0) {
            for(int j = i * i; j < 87000000; j += i * 2) {
                mark[j / 2] = 1;
            }
        }
    }
    for(int i = 3; i <= 87000000; i +=2) {
        if(mark[i / 2] == 0) {
            prime[o ++] = i;
        }
    }
}
