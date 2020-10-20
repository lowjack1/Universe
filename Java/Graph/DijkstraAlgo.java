import java.util.List;
import java.util.PriorityQueue;

public class DijkstraAlgo {

    final int INF = (1 << 29);

    public void solve(List<Pair> graph[], int src, int vertices) {
        int dis[] = new int[vertices];
        boolean vis[] = new boolean[vertices];
        PriorityQueue<Pair> q = new PriorityQueue<>();
        for (int i = 0; i < vertices; i++) dis[i] = INF;

        q.offer(new Pair(src, 0)); // node, cost
        int cnt = vertices;
        dis[src] = 0;

        while (!q.isEmpty() && cnt > 0) {
            Pair cur = q.poll();
            int u = cur.node;
            if (vis[u]) continue;
            vis[u] = true;
            cnt--;
            for (Pair child : graph[u]) {
                int v = child.node, cost = child.cost;
                if (vis[v]) continue;
                if (dis[v] > dis[u] + cost) dis[v] = dis[u] + cost;
                q.offer(new Pair(v, dis[v]));
            }
        }

        for (int i = 0; i < vertices; i++) {
            System.out.println(src + "=>" + i + "=" + dis[i]);
        }

    }

    class Pair implements Comparable<Pair> {
        int node, cost;
        public Pair(int node, int cost) {
            this.node = node;
            this.cost = cost;
        }
        public int compareTo(Pair that) {
            return this.cost - that.cost;
        }
    }
}
