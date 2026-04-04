import java.io.*;
import java.util.*;

// 41분, 42퍼 틀
// 49분, 힌트보기

public class Main {
    static int N, M;
    static int dp[][][];    // r, c, 방향
    static int matrix[][];
    static int dirs[][] = {{-1, -1}, {-1, 0}, {-1, 1}}; // 왼, 중, 오

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        dp = new int[N][M][3];  // 마지막: dir의 index
        matrix = new int[N][M];

        for (int r = 0; r < N; r++) {
            st = new StringTokenizer(br.readLine());
            for (int c = 0; c < M; c++) {
                matrix[r][c] = Integer.parseInt(st.nextToken());
                if (r == 0) Arrays.fill(dp[r][c], matrix[r][c]);
            }
        }

        for (int r = 1; r < N; r++) {
            for (int c = 0; c < M; c++) {
                int cur = matrix[r][c];
                int prevLeftDir  = inBound(r-1, c+1) ? dp[r-1][c+1][0] : 1_000_000;
                int prevMidDir   = inBound(r-1, c)   ? dp[r-1][c][1]   : 1_000_000;
                int prevRightDir = inBound(r-1, c-1) ? dp[r-1][c-1][2] : 1_000_000;
            
                dp[r][c][0] = Math.min(prevMidDir , prevRightDir) + cur;
                dp[r][c][1] = Math.min(prevLeftDir, prevRightDir) + cur;
                dp[r][c][2] = Math.min(prevLeftDir, prevMidDir  ) + cur;
            }
        }

        int result = dp[N-1][0][0];
        for (int c = 0; c < M; c++) {
            int e[] = dp[N-1][c];
            Arrays.sort(e);
            result = Math.min(result, e[0]);
        }
        System.out.println(result);
    }

    static boolean inBound(int r, int c) {
        return r >= 0 && c >= 0 && r < N && c < M;
    }
}