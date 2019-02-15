#include <bits/stdc++.h>
using namespace std;

template < typename T > class Linked_list;

template < typename T > class node {
    friend class Linked_list < T >;
    
    public:
        node(T data = 0, node < T > * next = NULL) :
        data(data), next(next) {}
    
    private:
        T data;
        node < T > * next;
};

template < typename T > class Linked_list {
    public:
        Linked_list();
        ~Linked_list();
        void add(T data);
        void print();
    private:
        node < T > * head;
        node < T > * tail;
};

template < typename T > Linked_list < T > :: Linked_list() :
    head(NULL), tail(NULL) {}
    
template < typename T > Linked_list < T > :: ~Linked_list() {
    if(head) {
        node < T > * p = head;
        node < T > * q;
        while(p != NULL) {
            q = p;
            p = p -> next;
            delete q;
        }
    }
    cout << "\n";
}

template < typename T > void Linked_list < T > :: add(T data) 
{
    if(head) {
        tail -> next = new node < T > (data);
        tail = tail -> next;
    }    
    else {
        tail = head = new node < T > (data);
    }
}

template < typename T > void Linked_list < T > :: print() 
{
    node < T > * p = head;
    while(p) {
        cout << p -> data << " ";
        p = p -> next;
    }
}
int main()
{
    Linked_list < int > l;
    
    for(int i = 1; i <= 10; i ++) {
        l.add(i);
    }
    l.print();
    return 0;
}
