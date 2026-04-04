import java.util.*;
import java.io.*;

// 90분, 16퍼 틀

public class Main {
    static int N; // node 수
    static int M; // edge tn
    static int T; // 목적지 후보 수

    static int S; // 시작 점
    static int G, H; // 필수로 건너는 곳

    static int candidates[];
    static List<Node>[] graph;
    static int distS[];
    static int distH[];
    static int distG[];
    public static void main(String args[]) throws Exception {
        BufferedReader  br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder   sb = new StringBuilder();

        int TC = Integer.parseInt(st.nextToken());

        for (int tc = 0; tc < TC; tc++) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            T = Integer.parseInt(st.nextToken());

            st = new StringTokenizer(br.readLine());
            S = Integer.parseInt(st.nextToken());
            G = Integer.parseInt(st.nextToken());
            H = Integer.parseInt(st.nextToken());

            graph = new ArrayList[N+1];
            for (int i = 0; i < N+1; i++)  graph[i] = new ArrayList<>();

            for (int i = 0; i < M; i++) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                int d = Integer.parseInt(st.nextToken());
                graph[a].add(new Node(b, d));
                graph[b].add(new Node(a, d));
            }
        
            candidates = new int[T];
            for (int i = 0; i < T; i++) {
                st = new StringTokenizer(br.readLine());
                candidates[i] = Integer.parseInt(st.nextToken());
            }

            // 3번 dijkstra
            distS = dijkstra(S);
            distG = dijkstra(H);
            distH = dijkstra(G);

            List<Integer> result = new ArrayList<>();
            for (int dest : candidates) {
                long comp1 = (long) distS[H] + distG[G] + distH[dest];
                long comp2 = (long) distS[G] + distH[H] + distG[dest];
                
                if (distS[dest] == Math.min(comp1, comp2)) result.add(dest);
            }

            Collections.sort(result);
            for (int e : result)  sb.append(e + " ");
            sb.append("\n");
        }

        System.out.print(sb);
    }
    
    static int[] dijkstra(int start) {
        int[] dist = new int[N + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start] = 0;

        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(start, 0));

        while (!pq.isEmpty()) {
            Node cur = pq.poll();

            if (cur.cost > dist[cur.to])  continue;

            for (Node nxt : graph[cur.to]) {
                if (dist[cur.to] + nxt.cost < dist[nxt.to]) {
                    dist[nxt.to] = dist[cur.to] + nxt.cost;
                    pq.offer(new Node(nxt.to, dist[nxt.to]));
                }
            }
        }
        return dist;
    }

    static class Node implements Comparable<Node> {
        int to, cost;

        Node(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node o) {
            return Integer.compare(this.cost, o.cost);
        }
    }
}