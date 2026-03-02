import java.util.*;
import java.io.*;

public class Main {
    static int T;
    static int N, M, W;
    static int[] matrix;
    static List<Node> doros;
    
    
    public static void main(String[] args) throws Exception {
        BufferedReader  br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder   sb = new StringBuilder();

        T = Integer.parseInt(st.nextToken());
        for (int tc = 0; tc < T; tc++) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            W = Integer.parseInt(st.nextToken());

            // 초기화
            matrix = new int[N+1];
            doros = new ArrayList<>();

            // 도로 저장, 양방향 (만약 있으면 min값 저장)
            int S, E, T;
            for (int i = 1; i <= M; i++) {
                st = new StringTokenizer(br.readLine());
                S = Integer.parseInt(st.nextToken());
                E = Integer.parseInt(st.nextToken());
                T = Integer.parseInt(st.nextToken());
                doros.add(new Node(S, E, T));
                doros.add(new Node(E, S, T));
            }
            // 웜홀 저장, 단방향 (만약 있으면 max값 저장)
            for (int i = 1; i <= W; i++) {
                st = new StringTokenizer(br.readLine());
                S = Integer.parseInt(st.nextToken());
                E = Integer.parseInt(st.nextToken());
                T = Integer.parseInt(st.nextToken());
                doros.add(new Node(S, E, -T));
            }

            // N-1번 edge 돌리기
            Arrays.fill(matrix, 0);
            for (int i = 0; i < N-1; i++) {
                hasMinusCycle();
            }
            
            if (hasMinusCycle()) {
                sb.append("YES").append("\n");
            } else {
                sb.append("NO").append("\n");
            }
        }

        System.out.print(sb);
    }

    static boolean hasMinusCycle() {
        boolean result = false;
        for (Node doro : doros) {
            if (matrix[doro.e] > matrix[doro.s] + doro.cost) {
                matrix[doro.e] = matrix[doro.s] + doro.cost;
                result = true;
            }
        }
        return result;
    }

    static class Node {
        int s;
        int e;
        int cost;
        public Node(int x, int y, int z) {
            s = x;
            e = y;
            cost = z;
        }
    }
}