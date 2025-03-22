import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static int N;
    static int dp[];
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        N = s.nextInt();
        dp = new int[N+1];
        Arrays.fill(dp, 0);

        for (int i = 2; i <= N; i++) {
            dp[i] = 1 + dp[i-1];
            if (i % 3 == 0) {
                dp[i] = Math.min(dp[i], 1 + dp[i/3]);
            }
            if (i % 2 == 0) {
                dp[i] = Math.min(dp[i], 1 + dp[i/2]);
            }
        }
        System.out.println(dp[N]);
    }
}