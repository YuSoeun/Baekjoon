import java.util.*;
import java.io.*;

public class Main {
    static int R, C;
    static int[][] matrix;
    static boolean[][][][] visited;
    static int[][] udlr = { { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } };
    static Queue<int[]> queue;

    static boolean inBound(int r, int c) {
        return r >= 0 && r < R && c >= 0 && c < C;
    }

    static int[] move(int row, int col, int[] dir) {
        int dist = 0; // 이동 거리
        while (inBound(row + dir[0], col + dir[1]) && matrix[row + dir[0]][col + dir[1]] != -1) {
            row += dir[0];
            col += dir[1];
            dist++;
            if (matrix[row][col] == -4) break; // 구멍에 도달하면 멈춤
        }
        return new int[] { row, col, dist };
    }

    public static int bfs(int rowR, int colR, int rowB, int colB) {
        visited = new boolean[R][C][R][C];
        queue = new LinkedList<>();
        queue.add(new int[] { rowR, colR, rowB, colB, 0 }); // 초기 상태
        visited[rowR][colR][rowB][colB] = true;

        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int curRowR = cur[0], curColR = cur[1];
            int curRowB = cur[2], curColB = cur[3];
            int count = cur[4];

            if (count > 10) return -1; // 10번 초과 시 실패

            for (int[] dir : udlr) {
                // 빨간 구슬 이동
                int[] red = move(curRowR, curColR, dir);
                int nextRowR = red[0], nextColR = red[1], redDist = red[2];

                // 파란 구슬 이동
                int[] blue = move(curRowB, curColB, dir);
                int nextRowB = blue[0], nextColB = blue[1], blueDist = blue[2];

                // 경계 초과 확인
                if (!inBound(nextRowR, nextColR) || !inBound(nextRowB, nextColB)) continue;

                // 파란 구슬이 구멍에 빠지면 실패
                if (matrix[nextRowB][nextColB] == -4) continue;

                // 빨간 구슬이 구멍에 빠졌다면 성공
                if (matrix[nextRowR][nextColR] == -4) return count + 1;

                // 두 구슬이 같은 위치에 도달한 경우 처리
                if (nextRowR == nextRowB && nextColR == nextColB) {
                    if (redDist > blueDist) { // 빨간 구슬이 더 멀리 이동한 경우
                        nextRowR -= dir[0];
                        nextColR -= dir[1];
                    } else { // 파란 구슬이 더 멀리 이동한 경우
                        nextRowB -= dir[0];
                        nextColB -= dir[1];
                    }
                }

                // 방문 여부 확인 후 큐에 추가
                if (!visited[nextRowR][nextColR][nextRowB][nextColB]) {
                    visited[nextRowR][nextColR][nextRowB][nextColB] = true;
                    queue.add(new int[] { nextRowR, nextColR, nextRowB, nextColB, count + 1 });
                }
            }
        }

        return -1; // 실패
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        matrix = new int[R][C];
        visited = new boolean[R][C][R][C];
        int rowR = 0, colR = 0, rowB = 0, colB = 0;

        for (int i = 0; i < R; i++) {
            String line = br.readLine();
            for (int j = 0; j < C; j++) {
                char temp = line.charAt(j);

                switch (temp) {
                    case '#': // 벽
                        matrix[i][j] = -1;
                        break;
                    case 'R': // 빨간 구슬
                        rowR = i;
                        colR = j;
                        matrix[i][j] = 0; // 빈 칸으로 변경
                        break;
                    case 'B': // 파란 구슬
                        rowB = i;
                        colB = j;
                        matrix[i][j] = 0; // 빈 칸으로 변경
                        break;
                    case 'O': // 구멍
                        matrix[i][j] = -4;
                        break;
                    default: // 빈 칸
                        matrix[i][j] = 0;
                }
            }
        }

        int result = bfs(rowR, colR, rowB, colB);
        if (result > 10) {
            result = -1;
        }

        System.out.println(result);
    }
}
