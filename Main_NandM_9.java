import java.io.*;
import java.util.*;

public class Main_NandM_9 {
    static int N, M;
    static int numbers[], result[];
    static boolean visited[];
    static StringBuilder sb;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        sb = new StringBuilder();

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        st      = new StringTokenizer(br.readLine());
        numbers = new int[N];
        visited = new boolean[N];
        result  = new int[M];

        for (int i = 0; i < N; i++) {
            numbers[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(numbers);
        traverse(0);

        System.out.print(sb);
    }

    static void traverse(int depth) {
        if (depth >= M) {
            String str = "";
            for (int e : result) sb.append(e + " ");
            sb.append("\n");
            return;             // Don't forget return!!!!
        }

        int prev = 0;
        for (int i = 0; i < N; i++) {
            if (!visited[i] && prev != numbers[i]) {
                visited[i] = true;
                result[depth] = numbers[i];
                prev = numbers[i];
                traverse(depth+1);
                visited[i] = false;
            }
        }
    }
}
