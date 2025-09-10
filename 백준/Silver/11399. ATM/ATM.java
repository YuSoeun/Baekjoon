
import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static int[] P;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        P = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            P[i] = Integer.parseInt(st.nextToken());;
        }
        Arrays.sort(P);

        int sum = 0;
        int result = 0;
        for (int e : P) {
            sum += e;
            result += sum;
        }

        System.out.println(result);
    }
}