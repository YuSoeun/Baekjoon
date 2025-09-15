import java.io.*;
import java.util.*;

// 15m

public class Main_15650_N과M_2 {
    static int N, M;
    static int result[];
    static StringBuffer sb;

    public static void main(String[] args) throws Exception {
        BufferedReader   br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        sb = new StringBuffer();

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        result = new int[M];

        traverse(0, 1);
        System.out.print(sb);
    }

    static void traverse(int depth, int cur) {
        if (depth >= M) {
            for (int e : result) sb.append(e + " ");
            sb.append("\n");
            return;
        }
        if (cur > N)  return;

        for (int i = cur; i <= N; i++) {
            result[depth] = i;
            traverse(depth+1, i+1);
        }
    }
}