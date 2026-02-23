import java.util.*;
import java.io.*;

public class Main {
    static int N, M;
    static int[][] dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    static class Node {
        int r;
        int c;
        int value;
        public Node(int x, int y, int z) {
            r = x;
            c = y;
            value = z;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        
        int[][] matrix = new int[N][M];
        int[][] answer = new int[N][M];
        int sr = 0, sc = 0;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                matrix[i][j] = Integer.parseInt(st.nextToken());
                if (matrix[i][j] == 2) {
                    sr = i;
                    sc = j;
                } else if (matrix[i][j] == 1) {
                    answer[i][j] = -1;
                }
            }
        }

        answer[sr][sc] = 0;

        // 목표지점부터 bfs
        Queue<Node> q = new ArrayDeque<>();
        q.offer(new Node(sr, sc, 0));
        
        while(!q.isEmpty()) {
            Node cur = q.poll();
            for (int[] dir : dirs) {
                int nr = cur.r + dir[0];
                int nc = cur.c + dir[1];

                if (isValid(nr, nc) && matrix[nr][nc] == 1) {
                    matrix[nr][nc] = 0;
                    answer[nr][nc] = cur.value + 1;
                    q.offer(new Node(nr, nc, cur.value + 1));
                }
            }
        }

        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                sb.append(answer[i][j]).append(" ");
            }
            sb.append("\n");
        }
        System.out.print(sb);
    }

    static boolean isValid(int r, int c) {
        return r >= 0 && c >= 0 && r < N && c < M;
    }
}