import java.util.*;
import java.io.*;

// 최대 최소로 사용되는 값 찾기
public class Main {
    static int N;
    static int[][] dirs = {{1, -1}, {1, 0}, {1, 1}};

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        int e;
        int[][] dpMax = new int[N][3]; // [depth][col]
        int[][] dpMin = new int[N][3]; // [depth][col]
        for (int r = 0; r < N; r++) {
            st = new StringTokenizer(br.readLine());

            for (int c = 0; c < 3; c++) {
                e = Integer.parseInt(st.nextToken());
                dpMax[r][c] = e;
                dpMin[r][c] = e;
            }
        }

        for (int r = N-2; r >= 0; r--) {
            for (int c = 0; c < 3; c++) {
                int max = 0;
                int min = Integer.MAX_VALUE;

                // 다음 행에서 하나 선택했을 경우의 max/min 값 저장
                for (int[] dir : dirs) {
                    int pr = r + dir[0];
                    int pc = c + dir[1];
                    
                    if (isValid(pr, pc)) {
                        max = Math.max(dpMax[pr][pc], max);
                        min = Math.min(dpMin[pr][pc], min);
                    }
                }
                dpMax[r][c] += max;
                dpMin[r][c] += min;
            }
        }

        int max = Math.max(dpMax[0][0], Math.max(dpMax[0][1], dpMax[0][2]));
        int min = Math.min(dpMin[0][0], Math.min(dpMin[0][1], dpMin[0][2]));
        System.out.println(max + " " + min);
    }

    static boolean isValid(int r, int c) {
        return r >= 0 && c >= 0 && r < N && c < 3;
    }
}