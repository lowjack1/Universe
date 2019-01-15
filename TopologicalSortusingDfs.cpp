#include <iostream>
#include <vector>
#include <stack>
#include <string.h>

using namespace std;

vector < int > v[100];
bool visited[100];
stack < int > s;

void dfs(int n)
{
	visited[n] = 1;
	for(auto x: v[n]) {
		if(!visited[x]) {
			dfs(x);
		} 
	}
	s.push(n);
}

int main()
{
   	int n, m;
   	cin >> n >> m;
   	for(int i = 0; i < m; i ++) {
   		int x, y;
   		cin >> x >> y;
   		v[x].push_back(y);
   	}

   	for(int i = 0; i < n; i ++) {
   		if(!visited[i]) {
   			dfs(i);
   		}
   	}

   	while(!s.empty()) {
   		cout << s.top() << " ";
   		s.pop();
   	}
   cout << "\n";
   return 0;
}
