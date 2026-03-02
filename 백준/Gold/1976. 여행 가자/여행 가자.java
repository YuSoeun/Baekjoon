import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static int[][] matrix;
    static boolean[] visited;
    static int[] plan;


    public static void main(String[] args) throws Exception {
        BufferedReader  br = new BufferedReader(new InputStreamReader(System.in));
        // init
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        matrix = new int[N+1][N+1];
        visited = new boolean[N+1];

        st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        plan = new int[M];
        
        int S, E, W;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                matrix[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            plan[i] = Integer.parseInt(st.nextToken()) - 1;
        }

        solution();

        for (int i = 0; i < M; i++) {
            if (!visited[plan[i]]) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }

    static void solution() {
        // bfs from plan[1]
        Queue<Integer> q = new ArrayDeque<>();
        q.offer(plan[0]);
        visited[plan[0]] = true;

        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int i = 0; i < N; i++) {
                if (matrix[cur][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.offer(i);
                }
            }
        }
    }
}