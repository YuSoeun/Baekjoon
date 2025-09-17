import java.io.*;
import java.util.*;

public class Main_2473_세용액 {
    static long A[];
    static long result[];
    static int N;

    public static void main(String[] args) throws IOException {
        BufferedReader  br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        A = new long[N];
        result = new long[3];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }
        
        Arrays.sort(A);

        long min = Long.MAX_VALUE;
        for (int mid = 1; mid < N-1; mid++) {
            int left = 0, right = N-1;

            while (left < mid && mid < right) {
                long sum = A[mid] + A[left] + A[right];
                if (Math.abs(sum) < min) {
                    min = Math.abs(sum);
                    result[0] = A[left];
                    result[1] = A[mid];
                    result[2] = A[right];
                }

                if (sum > 0)        right--;
                else if (sum < 0)   left++;
                else                break;
            }
        }

        // System.out.println(min);
        for (int i = 0; i < 3; i++) {
            System.out.print(result[i] + " ");
        }
    }
}