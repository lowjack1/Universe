/*input
bacaabababababbba
*/

/*  Manacher's Algorithm is used to find Longest Palindromic Substring in Linear Time
	Time Complexity: O(n)
*/

#include <iostream>
#include <string.h>

int main()
{
	std::string s1 = "", s2;
	std::cin >> s2;
	
	// Making new string
	for(int i = 0; i < s2.length(); i ++) {
		s1 += '*';
		s1 += s2[i];
	}
	s1 += '*';
	
	// length of inputted string
	int l = s1.length();
	
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
	for(int i = 2; i < l; i ++) {
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
	std::cout << "Length of Longest Palindromic Substring is ";
	std::cout << maxLen << "\n";
	int strt = (maxLpsCenter - maxLen) / 2;
	int end = maxLen;
	std::cout << "String is ";
	std::cout << s2.substr(strt, end) << "\n";
	return 0;
}

/*  Expected Output
	Length of Longest Palindromic Substring is 9
	String is ababababa
*/