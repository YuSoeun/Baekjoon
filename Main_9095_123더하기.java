import java.io.*;
import java.util.*;

public class Main_9095_123더하기 {
    static int sum[];
    static int T;

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        sum = new int[12];
        sum[1] = 1;
        sum[2] = 2;
        sum[3] = 4;

        for (int i = 4; i <= 11; i++) {
            sum[i] = sum[i-1] + sum[i-2] + sum[i-3];
        }

        T = Integer.parseInt(st.nextToken());

        StringBuffer sb = new StringBuffer();
        int N;
        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            sb.append(sum[N] + "\n");
        }

        System.out.println(sb);
    }
}