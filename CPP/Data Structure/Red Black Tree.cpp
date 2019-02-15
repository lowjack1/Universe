/* Implementation of left leaning Red Black tree */

/* color of Node is true if the link from the parent is Red */

#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node * link[2];
    bool color;
    int size;
};

struct node * make_node(int data) 
{
    struct node * n = new struct node;
    
    n -> data = data;
    n -> link[0] = n -> link[1] = NULL;
    
    n -> color = 1;
    n -> size = 1;
    return n;
}

int size(struct node * root) 
{
    if(root == NULL) {
        return 0;
    }
    return root -> size;
}

bool is_empty(struct node * root)
{
    return (root == NULL);
}

bool isRed(struct node * root)
{
    if(root == NULL) {
        return 0;
    }
    return (root -> color == 1);
}

/* when right subtree i.e x of root is colored red, then do left rotation and 
   making x as root and changing color of x as that of root and color of root to 
   red */

struct node * rotate_left(struct node * root)
{
    assert(isRed(root -> link[1]));
    struct node * x = root -> link[1];
    root -> link[1] = x -> link[0];
    x -> link[0] = root;
    
    x -> color = root -> color;
    root -> color = 1;
    x -> size = root -> size;
    root -> size = size(root -> link[0]) + size(root -> link[1]) + 1;
    return x;
}

/* when left subtree i.e x of root is colored red, then do right rotation and 
   making x as root and changing color of x as that of root and color of root to 
   red.  Right rotaion is used when only in right leaning red black tree */
   
struct node * rotate_right(struct node * root)
{
    assert(isRed(root -> link[0]));
    struct node * x = root -> link[0];
    root -> link[0] = x -> link[1];
    x -> link[1] = root;
    
    x -> color = root -> color;
    root -> color = 1;
    x -> size = root -> size;
    root -> size = size(root -> link[0]) + size(root -> link[1]) + 1;
    
    return x;
}

/* color fip is required when both child of root is colored red then in this 
   condition change the color of both child black and color of root red */
   
void flip_color(struct node * root)
{
    if(isRed(root)) {
        root -> color = 0; 
    }    
    root -> color = 1;
    root -> link[0] -> color = 0;
    root -> link[1] -> color = 0;
    //return root;
}

void print(struct node * root)
{
    queue < node * > q;
    q.push(root);
    while(!q.empty()) {
        struct node * p = q.front();
        q.pop();
        cout << p -> data << " ";
        if(p -> link[0] != NULL) {
            q.push(p -> link[0]);
        }
        if(p -> link[1] != NULL) {
            q.push(p -> link[1]);
        }
    }
}

struct node * insert(struct node * root, int data)
{
    if(root == NULL) {
        root = make_node(data);
        return root;
    }
    int dir = root -> data < data;
    root -> link[dir] = insert(root -> link[dir], data);

    /* Changing the color of root */
    root -> color = 0;
    
    if(isRed(root -> link[1]) and !isRed(root -> link[0])) {
        root = rotate_left(root);
    }
    else if(isRed(root -> link[0]) and isRed(root -> link[0] -> link[0])) {
        root = rotate_right(root);
    }
    else if(isRed(root -> link[0]) and isRed(root -> link[1])) {
        flip_color(root);
    }
    root -> size = size(root -> link[0]) + size(root -> link[1]) + 1;
    return root;
}

int main() 
{
    cout << "\n";
    struct node * root = NULL;
    root = insert(root, 1);
    for(int i = 2; i <= 10; i ++) {
        root = insert(root, i);
    }
    print(root);
    return 0;
}
