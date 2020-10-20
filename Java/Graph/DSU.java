public class DSU {

    int parent[];
    int rank[];

    int edges;
    int vertices;

    public DSU(int edges, int vertices) {
        this.edges = edges;
        this.vertices = vertices;
        parent = new int[vertices];
        rank = new int[vertices];
        makeSet();
    }

    public  void makeSet() {
        for (int i = 0; i < vertices; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    public int find(int node) {
        if (node == parent[node]) return node;
        else return parent[node] = find(parent[node]);
    }

    public boolean connected(int a, int b) {
        return find(a) == find(b);
    }

    public void union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b]) { int temp = a; a = b; b = temp; }
            parent[b] = a;
            rank[a] += rank[b];
        }
    }
}

