#include <bits/stdc++.h>

using namespace std;

struct Trie {
    bool isleaf;
    int words;
    int prefix;
    unordered_map < char, Trie* > m;
};

struct Trie * getnode() 
{
    struct Trie * node = new struct Trie;
    node -> isleaf = false;
    node -> words = 0;
    node -> prefix = 0;
    
    return node;
}

void insert(Trie * & head, string s)
{
    if(head == NULL) {
        head = getnode();
    }
    Trie * curr = head;
    int i = 0;
    while(i < s.length()) {
        if(curr -> m.find(s[i]) == curr -> m.end()) {
            curr -> m[s[i]] = getnode();
        }
        curr -> m[s[i]] -> prefix = curr -> m[s[i]] -> prefix + 1;
        curr = curr -> m[s[i]];
        i ++;
    }
    curr -> isleaf = true;    
    curr -> words ++;
}

int countPrefix(struct Trie * head, string s)
{
    if(head == NULL) {
        return 0;
    }
    int i = 0;
    struct Trie * curr = head;
    while(i < s.length()) {
        curr = curr -> m[s[i]];
        if(curr == NULL) {
            return 0;
        }
        i ++;
    }
    return curr -> prefix;
}

int countWords(struct Trie * head, string s)
{
    if(head == NULL) {
        return 0;
    }    
    int i = 0;
    struct Trie * curr = head;
    while(i < s.length()) {
        curr = curr -> m[s[i]];
        if(curr == NULL) {
            return 0;
        }
        i ++;
    }
    return curr -> words;
}

bool search(struct Trie * head, string s) 
{
    if(head == NULL) {
        return false;
    }
    Trie * curr = head;
    int i = 0;
    while(i < s.length()) {
        curr = curr -> m[s[i]];
        if(curr == NULL) {
            return false;
        }
        i ++;
    }
    return curr -> isleaf;
}

int main()
{
    struct Trie * head = NULL;
    insert(head, "root");
    insert(head, "the");
    insert(head, "there");
    insert(head, "three");
    
    cout << countPrefix(head, "there") << "\n";
    cout << countWords(head, "the") << "\n";
    cout << countPrefix(head, "the") << "\n";
    cout << search(head, "root");
    
    return 0;
}
