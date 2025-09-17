import java.io.*;
import java.util.*;

// 8m

public class Main_N과M_3 {
    static int N, M;
    static int result[];
    static StringBuilder sb;

    static void traverse(int depth) {
        if (depth >= M) {
            for (int e : result) sb.append(e + " ");
            sb.append("\n");
            return;
        }

        for (int i = 1; i <= N; i++) {
            result[depth] = i;
            traverse(depth+1);
        }
    }

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        result = new int[M];

        sb = new StringBuilder();

        traverse(0);
        System.out.print(sb);
    }
}