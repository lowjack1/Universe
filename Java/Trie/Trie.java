class Trie {

    Node root;

    public Trie() {
        root = new Node();
    }
    
    public void insert(String word) {
        Node cur = root;
        for (char c : word.toCharArray()) {
            int idx = (int) (c - 'a');
            if (cur.child[idx] == null) cur.child[idx] = new Node();
            cur = cur.child[idx];
        }
        cur.isEnd = true;
    }
    
    public boolean search(String word) {
        Node cur = root;
        for (char c : word.toCharArray()) {
            int idx = (int) (c - 'a');
            if (cur.child[idx] == null) return false;
            cur = cur.child[idx];
        }
        return cur.isEnd;
    }
    
    public boolean startsWith(String prefix) {
        Node cur = root;
        for (char c : prefix.toCharArray()) {
            int idx = (int) (c - 'a');
            if (cur.child[idx] == null) return false;
            cur = cur.child[idx];
        }
        return true;
    }
    
    class Node {
        Node child[] = new Node[26];
        boolean isEnd;
    }
}