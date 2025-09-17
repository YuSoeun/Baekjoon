
import java.io.*;
import java.util.*;

public class Main_N과M_1 {

    static int N, M;
    static int result[];
    static boolean visited[];
    static StringBuffer sb;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        sb = new StringBuffer();

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        result  = new int[M];
        visited = new boolean[N];

        traverse(0);
        System.out.print(sb);
    }

    static void traverse(int resultIndex) {
        if (resultIndex >= M) {
            for (int e : result)  sb.append(e + " ");
            sb.append("\n");
            return;
        }

        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                visited[i] = true;
                result[resultIndex] = i+1;
                traverse(resultIndex + 1);
                visited[i] = false;
            }
        }
    }
}