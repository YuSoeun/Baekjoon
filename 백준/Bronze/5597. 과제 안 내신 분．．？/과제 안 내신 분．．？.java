import java.io.*;
import java.util.*;

class Main
{
    public static void main(String[] args) throws Exception{
        BufferedReader sb = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        boolean[] visited = new boolean[30];
        int N = 30;
        for (int i = 0; i < N-2; i++) {
            st = new StringTokenizer(sb.readLine());
            int n = Integer.parseInt(st.nextToken()) - 1;
            visited[n] = true;
        }

        int[] answer = new int[2];
        int j = 0;
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                answer[j++] = i;
            }
        }

        Arrays.sort(answer);

        for (int e : answer) {
            System.out.println(e+1);
        }
    }
}