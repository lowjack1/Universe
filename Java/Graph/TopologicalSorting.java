import java.util.List;
import java.util.Stack;

public class TopologicalSorting {
    Stack<Integer> st = new Stack<>();

    public Stack<Integer> topologicalSort(int vertices, List<Integer> adj[]) {
        boolean visited[] = new boolean [vertices + 1];
        for (int i = 1;  i <= vertices; i++)  {
            if (!visited[i]) {
                dfs(i, adj, visited);
            }
        }
        return st;
    }

    public void dfs(int node, List<Integer> adj[], boolean visited[]) {
        visited[node] = true;
        for (int child : adj[node]) {
            if (!visited[child]) {
                dfs(child, adj, visited);
            }
        }
        st.push(node);
    }
}
