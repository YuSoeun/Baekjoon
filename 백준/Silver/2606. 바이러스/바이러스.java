/*
 * 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수
 * N: 컴퓨터의 수 (양의 정수 <= 100)
 * M: 간선 수
 * M - 간선 쌍
 */

import java.util.*;
import java.io.*;

public class Main {
    static int N, M;
    static int computer[][];
    static boolean visited[];
    static int result;

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());

        computer = new int[N+1][N+1];
        visited = new boolean[N+1];

        int from, to;
        for (int i = 1; i <= M; i++) {
            st = new StringTokenizer(br.readLine());
            from = Integer.parseInt(st.nextToken());
            to   = Integer.parseInt(st.nextToken());
            computer[from][to] = 1;
            computer[to][from] = 1;
        }

        result = 0;
        visited[1] = true;
        bfs(1);
        System.out.println(result);
    }

    static void bfs(int from) {
        for (int i = 1; i <= N; i++) {
            if (computer[from][i] == 1 && !visited[i]) {
                visited[i] = true;
                result++;
                bfs(i);
            }
        }
    }
}