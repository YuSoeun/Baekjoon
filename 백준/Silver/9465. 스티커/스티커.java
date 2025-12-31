import java.io.*;
import java.util.*;

public class Main {
    
    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuffer sb = new StringBuffer();
        int N, M;

        N = Integer.parseInt(st.nextToken());
        int[][] sticker = new int[2][100_001];
        int[][] dp = new int[3][100_001];

        while (N-- > 0) {
            st = new StringTokenizer(br.readLine());
            M = Integer.parseInt(st.nextToken());

            for (int i = 0; i < 2; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < M; j++) {
                    sticker[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            // Case: 한 열에서 할 수 있는 경우의 수 저장
            //   0) 위 스티커 선택
            //   1) 아래 스티커 선택
            //   2) 선택 없음
            dp[0][0] = sticker[0][0];
            dp[1][0] = sticker[1][0];
            dp[2][0] = 0;

            for (int j = 1; j < M; j++) {
                dp[0][j] = sticker[0][j] + Math.max(dp[1][j-1], dp[2][j-1]);
                dp[1][j] = sticker[1][j] + Math.max(dp[0][j-1], dp[2][j-1]);
                dp[2][j] = Math.max(dp[0][j-1], Math.max(dp[1][j-1], dp[2][j-1]));
            }

            sb.append(Math.max(dp[0][M-1], Math.max(dp[1][M-1], dp[2][M-1])) + "\n");
        }
        System.out.print(sb);
    }
}