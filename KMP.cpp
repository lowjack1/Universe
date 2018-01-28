#include <bits/stdc++.h>

using namespace std;

// LPS = Longest Propre Prefix Subsequence which is also a suffix
const int N = 10000;
int lps[N];

void LPS(string pattern)
{
    int m = pattern.length();
    lps[0] = 0;
    int i = 1;
    int len = 0;
    while(i < m) {
        if(pattern[i] == pattern[len]) {
            lps[i ++] = ++len;
        }
        else {
            if(len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i ++] = 0;
            }
        }
    }
}

void KMP(string text, string pattern) 
{
    int m = pattern.length();
    int n = text.length();
    
    LPS(pattern);

    int i = 0, j = 0;
    while(i < n) {
        if(pattern[j] == text[i]) {
            i ++;
            j ++;
        }
        if(j == m) {
            cout << i - j << " ";
            j = lps[j - 1];
        } 
        else if(i < n and pattern[j] != text[i]) {
            if(j != 0) {
                j = lps[j - 1];
            }
            else {
                i ++;
            }
        }
    }
}

int main()
{
    string pattern, text;
    cin >> text >> pattern;
    KMP(text, pattern);
    return 0;
}
