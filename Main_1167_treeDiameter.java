import java.io.*;
import java.util.*;

public class Main_1167_treeDiameter {
    static class Node {
        int to;
        int cost;

        public Node(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }
    }
    static int V;
    static int result;
    static ArrayList<Node> tree[];
    static boolean visited[];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        V = Integer.parseInt(st.nextToken());
        result = 0;
        visited = new boolean[V+1];
        tree = new ArrayList[V+1];
        
        int from, to, cost;
        for (int i = 0; i <= V; i++) {
            tree[i] = new ArrayList<>();
        }

        for (int i = 1; i <= V; i++) {
            st = new StringTokenizer(br.readLine());
            from = Integer.parseInt(st.nextToken());

            while (true) {
                to = Integer.parseInt(st.nextToken());
                if (to == -1)  break;
                cost = Integer.parseInt(st.nextToken());

                tree[from].add(new Node(to, cost));
            }
        }

        visited[1] = true;
        dfs(1);
        System.out.println(result);
    }

    static int dfs(int from) {
        int first = 0, second = 0;

        for (Node node : tree[from]) {
            // can make cycle?
            if (!visited[node.to]) {
                visited[node.to] = true;
            // System.out.println(from + " -> " + node.to + " cost: " + node.cost);
                int cost = dfs(node.to) + node.cost;

                if (cost > first) {
                    second = first;
                    first = cost;
                } else if (cost > second) {
                    second = cost;
                }
            }
        }

        result = Math.max(result, first + second);
        // System.out.println(result + " / " + first + second);

        return Math.max(first, second);
    }
}
