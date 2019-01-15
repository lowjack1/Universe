/*
	Solving recurrence relation by matrix exponentiation
	f(n) = f(n - 1) + f(n - 2) + 5
	f(0) = f(1) = 1
*/

#include <iostream>
#include <string.h>
using namespace std;

void multiply(int a[3][3], int b[3][3])
{
	int res[3][3];
	memset(res, 0, sizeof(res));
	for(int i = 0; i < 3; i ++) {
		for(int j = 0; j < 3; j ++) {
			for(int k = 0; k < 3; k ++) {
				res[i][j] += (a[i][k] * b[k][j]);
			}
		}
	}
	for(int i = 0; i < 3; i ++) {
		for(int j = 0; j < 3; j ++) {
			a[i][j] = res[i][j];
		}
	}
}

void binary_exp(int a[3][3], int n)
{
	int res[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
	while(n > 0) {
		if(n & 1) {
			multiply(res, a);
		}
		multiply(a, a);
		n >>= 1;
	}
	for(int i = 0; i < 3; i ++) {
		for(int j = 0; j < 3; j ++) {
			a[i][j] = res[i][j];
		}
	}
}

int main()
{
	int n;
	cin >> n;
	if(n <= 2) {
		cout << "1";
	}
	else {
		int a[3][3] = {{1, 1, 5}, {1, 0, 0}, {0, 0, 1}};
		binary_exp(a, n - 2);
		int d = a[0][0] * 1 + a[0][1] * 1 + a[0][2];
		cout << d;
	}
	return 0;
}
