import java.util.*;
import java.io.*;

// 90분, 16퍼 틀

public class Main {
    static int N; // node 수
    static int M; // edge tn
    static int T; // 목적지 후보 수

    static int S; // 시작 점
    static int G, H; // 필수로 건너는 곳

    static int destT[];
    static ArrayList<Map<Integer, Integer>> edges;
    static int distance2S[];
    static int distance2G[];
    static int distance2H[];
    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

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

            edges = new ArrayList<>();
            for (int i = 0; i < N+1; i++) {
                edges.add(new HashMap<>());
            }

            for (int i = 0; i < M; i++) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                int d = Integer.parseInt(st.nextToken());
                edges.get(a).put(b, d);
                edges.get(b).put(a, d);
            }
        
            destT = new int[T];
            for (int i = 0; i < T; i++) {
                st = new StringTokenizer(br.readLine());
                destT[i] = Integer.parseInt(st.nextToken());
            }

            // 3번 dijkstra
            distance2S = new int[N+1];
            distance2H = new int[N+1];
            distance2G = new int[N+1];
            dijkstra(distance2S, S);
            dijkstra(distance2H, H);
            dijkstra(distance2G, G);

            ArrayList<Integer> result = new ArrayList<>();
            for (int e : destT) {
                int comp = Integer.MAX_VALUE;
                
                if (distance2S[H] < Integer.MAX_VALUE && distance2G[e] < Integer.MAX_VALUE) {
                    comp = distance2S[H] + distance2H[G] + distance2G[e];
                }

                if (distance2S[G] < Integer.MAX_VALUE && distance2H[e] < Integer.MAX_VALUE) {
                    comp = Math.min(comp, distance2S[G] + distance2G[H] + distance2H[e]);
                }
                
                if (distance2S[e] == comp && comp != Integer.MAX_VALUE) result.add(e);
            }

            Collections.sort(result);
            for (int e : result)  sb.append(e + " ");
            sb.append("\n");
        }

        System.out.print(sb);
    }
    
    static void dijkstra(int[] fee, int start) {
        Queue<Integer> q = new ArrayDeque<>();
        Arrays.fill(fee, Integer.MAX_VALUE);
        q.offer(start);
        fee[start] = 0;

        while (!q.isEmpty()) {
            int cur = q.poll();
            for (Map.Entry<Integer, Integer> e : edges.get(cur).entrySet()) {
                if (fee[e.getKey()] > e.getValue() + fee[cur]) {
                    q.offer(e.getKey());
                    fee[e.getKey()] = e.getValue() + fee[cur];
                }
            }
        }
    }
}