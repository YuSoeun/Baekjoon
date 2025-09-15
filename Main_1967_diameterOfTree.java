import java.util.*;
import java.io.*;

public class Main_1967_diameterOfTree {
    static int N;
    static int result;
    static List<Node> tree[];

    static class Node {
        int to;
        int cost;

        public Node(int x, int y) {
            to   = x;
            cost = y;
        }
    }

    static int traverse(int from) {
        int child = 0;
        int first = 0, second = 0;

        for (Node node : tree[from]) {
            // System.out.println(from + " -> " + node.to + ": " + node.cost);
            child = node.cost + traverse(node.to);

            if (child > first) {
                second = first;
                first = child;
            } else if (child > second) { 
                second = child;
            }
        }

        result = Math.max(first + second, result);
        // System.out.println("maxChild: " + maxChild + " / " + result);
        return Math.max(first, second);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader  br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        tree = new ArrayList[N+1];
        for (int i = 0; i <= N; i++)  tree[i] = new ArrayList<>();
        result = 0;

        int from, to, cost;
        for (int i = 1; i < N; i++) {
            st   = new StringTokenizer(br.readLine());
            from = Integer.parseInt(st.nextToken());
            to   = Integer.parseInt(st.nextToken());
            cost = Integer.parseInt(st.nextToken());

            tree[from].add(new Node(to, cost));
        }

        traverse(1);
        System.out.println(result);
    }
}
