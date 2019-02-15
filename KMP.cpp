/*input
aaaaaab
aaa
*/

/*  Pattern Matching Alogrithm
    Time Complexity: O(n)
*/
#include <iostream>
#include <string>

// LPS = Longest Propre Prefix Subsequence which is also a suffix
const int N = 10000;
int lps[N];

void LPS(std::string pattern)
{
    int m = pattern.length(), i = 1, len = 0;
    lps[0] = 0;
    while(i < m) {
        if(pattern[i] == pattern[len]) {
            lps[i ++] = ++len;
        }
        else {
            if(!len) lps[i ++] = 0;
            else len = lps[len - 1];
        }
    }
}

void KMP(std::string text, std::string pattern) 
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
            std::cout << "Pattern found at index " << i - j + 1 << "\n";
            j = lps[j - 1];
        } 
        else if(i < n and pattern[j] != text[i]) {
            if(!j) i ++;
            else j = lps[j - 1];
        }
    }
}

int main()
{
    std::string pattern, text;
    std::cin >> text >> pattern;
    KMP(text, pattern);
    return 0;
}

/*  Expected Output

    Pattern found at index 1
    Pattern found at index 2
    Pattern found at index 3
    Pattern found at index 4

*/