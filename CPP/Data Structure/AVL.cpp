
#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    int balance;
    struct node * link[2];
};

struct node * make_node(int data) {
    struct node * n = new struct node;
    
    n -> data = data;
    n -> balance = 0;
    n -> link[0] = n -> link[1] = NULL;

    return node;
}

struct node * single(struct node * root, int dir) 
{
    struct node * save = root -> link[!dir];

    root -> link[!dir] = save -> link[dir];
    save -> link[dir] = root;

    return save;
}

struct node * doble(struct node * root, int dir) 
{
    root -> link[!dir] = single(root -> link[!dir], !dir);
    return single(root, dir);
}

struct node * adjust_balance(struct node * root, int dir, int bal)
{
    struct node * n = root -> link[dir];
    struct node * nn = n -> link[!dir];
    
    if(nn -> balance == 0) {
        root -> balance = n -> balance = 0;
    }
    else if(nn -> balance == bal) {
        root -> balance = -bal;
	n -> balance = 0;
    }
    else {
        root -> balance = 0;
	n -> balance = bal;
    }
    nn -> balance = 0;
}

struct node * insert_balance(struct node * root, int dir) 
{
    struct node * n = root -> link[dir];
    int bal = dir == 0 ? -1 : +1;

    if(n -> balance == bal) {
        root -> balance = n -> balance = 0;
	root = single(root, !dir);
    }
    else {
	adjust_balance(root, dir, bal);
	root = doble(root, !dir);
    }
    return root;
}

struct node * insert(struct node * root, int data, int *done) 
{
    if(root == NULL) {
       	root = make_node(data);
    }	    
    else {
        int dir = root -> data < data;
    	root -> link[dir] = insert(root -> link[dir], data, done);
	if(!*done) {
	    root -> balance += dir == 0 ? -1 : +1;
	    if(root -> balance == 0) {
	        *done = 1;
	    }
	    else if(abs(root -> balance) > 1) {
	        root = insert_balane(root, dir);
		*done = 1;
	    }
	}	
    }
    return root;
}

void bfs(int s) 
{
    queue < int > q;
    q.push(s);
    while(!q.empty()) {
        int p = q.top();
	cout << p << " ";
	q.pop();
	if(p -> link[0] != NULL) {
	    q.push(p -> link[0]);
	}
	if(p -> link[1] != NULL) {
	    q.push(p -> link[1]);
	}
    }
}

int main()
{
    struct node * root = make_node(1);
    int done = 0;
    for(int i = 2; i < 10; i ++) {
        root = insert(root, i, &done);
	done = 0;
    }
    bfs(1);
    return 0;    
}
