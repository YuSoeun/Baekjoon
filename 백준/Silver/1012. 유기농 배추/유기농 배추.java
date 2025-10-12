/*
 * 상하좌우 인접
 * 모든 밭 돌면서 1 만나면 bfs, visited 처리 (발견한 밭의 개수로 하기)
 * 가로길이 M(1 ≤ M ≤ 50)
 * 세로길이 N(1 ≤ N ≤ 50)
 * 배추가 심어져 있는 위치의 개수 K(1 ≤ K ≤ 2500)
 * K줄에는 배추의 위치 X(0 ≤ X ≤ M-1), Y(0 ≤ Y ≤ N-1)
 * 
 * -1: 배추인데 발견 x, 0: 빈 곳, 1 이상: 발견한 곳
 */

import java.util.*;
import java.io.*;

public class Main {
    static int T, M, N, K;
    static int result;
    static int matrix[][];
    static int udlr[][] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuffer sb = new StringBuffer();

        T = Integer.parseInt(st.nextToken());
        int from, to;
        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());
            M = Integer.parseInt(st.nextToken());
            N = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());

            matrix = new int[N][M];

            while (K-- > 0) {
                st = new StringTokenizer(br.readLine());
                to = Integer.parseInt(st.nextToken());
                from = Integer.parseInt(st.nextToken());

                matrix[from][to] = -1;
            }

            result = 0;
            for (int r = 0; r < N; r++) {
                for (int c = 0; c < M; c++) {
                    if (matrix[r][c] == -1) {
                        matrix[r][c] = ++result;
                        bfs(r, c);
                    }
                }
            }

            sb.append(result + "\n");
        }
        System.out.print(sb);
    }

    static void bfs(int r, int c) {
        for (int e[] : udlr) {
            int nr = r + e[1];
            int nc = c + e[0];
            if (!inBound(nr, nc)) continue;

            if (matrix[nr][nc] == -1) {
                matrix[nr][nc] = result;
                bfs(nr, nc);
            }
        }
    }

    static boolean inBound(int r, int c) {
        return r >= 0 && c >= 0 && r < N && c < M;
    }
}