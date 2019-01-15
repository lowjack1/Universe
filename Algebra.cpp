#include <iostream>
#include <string.h>

using namespace std;

string add(string s1, string s2)
{
    string s3 = "";
    int i = int(s1.length()) - 1;
    int j = int(s2.length()) - 1;
    int carry = 0;

    while(i >= 0 and j >= 0) {
        int c = (s1[i] - '0') + (s2[j] - '0') + carry;
        char cc = (c % 10) + '0';
        carry = c / 10;
        s3 = cc + s3; 
        i --, j --;
    }
    if(j >= 0) {
        i = j;
        s1 = s2;
    }
    while(i >= 0) {
        int c = (s1[i] - '0') + carry;
        char cc = (c % 10) + '0';
        s3 = cc + s3;
        carry = c / 10;
        i --;
    }
    while(carry) {
        char cc = (carry % 10) + '0';
        s3 = cc + s3;
        carry /= 10;
    }
    return s3;
}

string substract(string s1, string s2)
{
	bool flag = 0;
    if(s1 == s2) {
        return "0";
    }
    if(s1.length() == s2.length()) {
        int a = s1[0] - '0';
        int b = s2[0] - '0';
        if(a - b < 0) {
        	flag = 1;
        }
        else if(a - b == 0) {
        	int i = 1;
        	while(i < s1.length()) {
        		a = s1[i] - '0';
        		b = s2[i] - '0';
        		if(b > a) {
        			flag = 1;
        			break;
        		}
        		else if(b < a) {
        			break;
        		}
        		i ++;
        	}
        }
        if(flag) {
        	swap(s1, s2);
        }
    }
    else if(s2.length() > s1.length()) {
        flag = 1;
        swap(s1, s2);
    }
    string s3 = "";

    int i = int(s1.length()) - 1;
    int j = int(s2.length()) - 1;
    int carry = 0;

    while(i >= 0 and j >= 0) {
        int a = s1[i] - '0';
        int b = s2[j] - '0';
        if(a >= b) {
            char c = (a - b) + '0';
            s3 = c + s3;
        }
        else {
            char c = (10 + a - b) + '0';
            s3 = c + s3;
            int k = i - 1;
            while(s1[k] == '0' and k >= 0) {
                s1[k] = '9';
                k --;
            }
            s1[k] --;
        }
        i --, j --;
    }
    while(i >= 0) {
        s3 = s1[i] + s3;
        i --;
    }
    i = 0;
    int n = s3.length();
    while(s3[i] == '0' and i < n) {
        i ++;
    }
    if(i == n) {
        return "0";
    }
    return (flag) ? "-" + s3.substr(i, n): s3.substr(i, n);
}

// Used as a utility function for multiplication
string multi(string s1, int d, int o)
{
    string s2 = "";
    int carry = 0;
    for(int i = s1.length() - 1; i >= 0; -- i) {
        int c = (s1[i] - '0') * d + carry;
        char cc = (c % 10) + '0';
        s2 = cc + s2;
        carry = c / 10;
    }
    while(carry) {
        char c = (carry % 10) + '0';
        s2 = c + s2;
        carry /= 10;
    }
    for(int i = 0; i < o; ++ i) {
        s2 += "0";
    } 
    return s2;
}


string multiply(string s1, string s2)
{
    if(s1 == "0" or s2 == "0") {
        return "0";
    }
    if(s1.length() < s2.length()) {
        swap(s1, s2);
    }
    int o = 0;
    string s4 = "";
    for(int i = s2.length() - 1; i >= 0; -- i) {
        int d = s2[i] - '0';
        string s3 = multi(s1, d, o);
        if(!o) {
            s4 = s3;
        }
        else {
            s4 = add(s4, s3);
        }
        o ++;
    }
    int i = 0;
    int n = s4.length();
    while(s4[i] == '0' and i < n) {
        i ++;
    }
    if(i == n) {
        return "0";
    }
    return s4.substr(i, n);
}


int main() 
{
	cout << add("13985739723423423424242423", "9873407878483479234739472384") << "\n";
	cout << substract("393475983453457345999", "1345938475937220380820") << "\n";
	cout << multiply("13985739723423423424242423", "9873407878483479234739472384") << "\n";
	return 0; 
}
