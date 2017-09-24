#include <bits/stdc++.h>

using namespace std;

#define M 			50005
#define Fi			first
#define stop 		return
#define Se 			second
#define S(n) 		cin >> n
#define P(n) 	 	cout << n
#define mp 			make_pair
#define pb 			push_back
#define pp 			pop_back
#define pf 			pop_front
#define start 		int main()
#define space 		cout << " "
#define new_line 	cout << "\n"
#define	mem(n, i)	memset((n), (i), sizeof(n))
#define deci(n)		cout << fixed << setprecision(n)
#define F(i, n, r)  for(int i = (n); i < (r); i ++)
#define PI			3.14159265358979323846264338327951
#define fast 		ios_base:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long 			ll;
typedef set < int > 		st;
typedef stringstream 		ss;
typedef vector < ll > 		vl;
typedef vector < int > 		vi;
typedef map < ll, ll > 		ml;
typedef pair <int, int> 	p;
typedef vector < string > 	vs;
typedef map < string, ll > 	ms;
typedef map < string, int > mi;
typedef vector < p > 		vp;
typedef unsigned long long  ull;

template < typename T > inline T LCM(T a, T b) 		 { return (a * b) / GCD(a, b); }
template < typename T > inline T GCD(T a, T b) 		 { ll t; while(a) { t = a; a = b % a; b = t; } return b; }
template < typename T > inline T _max(T a, T b, T c) { return max( max( a, b ), c ); }
template < typename T > inline T _min(T a, T b, T c) { return min( min( a, b ), c ); }

const int inf 	  = 123456789;
const int neg_inf = -123456789;

start
{
	string s1 = "", s2;
	S(s2);
	
	// Length of inputted string
	ll l = s2.length();
	
	// Making new string
	F(i, 0, l) {
		s1 += '*';
		s1 += s2[i];
	}
	s1 += '*';
	
	// Updating lenth of string
	l = s1.length();
	
	int L[l]; // Array for Palindromic length
	L[0] = 1; /* since at 0th position there is '*' only so there is a palindome of length 1 */ 
	L[1] = 3; /* since at 1th position there is a digit so there is a palindrome of length 3 i.e., *digit* */
	
	
	/*
	* cc = center 
	* cl = center_Left
	* cr = center_Right
	* i = current_center
	* iMirror = Mirror of i
	* j = i_Left when taking i as center
	* k = i_right when taking i as center
	*/
	
	int cl = 0, cr = 2, cc = 1;
	int iMirror = 0, i = 0, j, k;
	int maxLen = 0;
    int maxLpsCenter = 0;
    
	bool expand = 0;
	// Applying Manacher Algorithm
	F(i, 2, l) {
		L[i] = 0;
		expand = 0;
		iMirror = 2 * cc - i;
		
		if(cr > i) {
			if(i + L[iMirror] / 2 < cr) {
				L[i] = L[iMirror];
			}
			else if(i + L[iMirror] / 2 > cr) {
				expand = 1;
				j = i - 1;
				k = i + 1;
			}
			else if(i + L[iMirror] / 2 == cr) {
				expand = 1;
				j = 2 * i - cr - 1;
				k = cr + 1; 
			}
		}
		else {
			j = i - 1;
			k = i + 1;
			expand = 1;
		}
		if(expand) {
			for(; j >= 0 and k < l; j --, k ++) {
				if(s1[j] != s1[k]) {
					break;
				}
			}
			k --, j ++;
			L[i] = k - j + 1;
			if(k > cr) {
				cc = i;
				cr = k;
				cl = j;
			}
		}
		if(L[i] / 2 > maxLen) {
			maxLen = L[i] / 2;
			maxLpsCenter = cc;
		}
	}
	P(maxLen), new_line;
	int strt = (maxLpsCenter - maxLen) / 2;
	int end = maxLen;
	P(s2.substr(strt, end));
	stop 0;
}
