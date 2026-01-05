import java.util.*;
import java.io.*;
import java.awt.Point;

class Solution {
    int[][] dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int matrix[][];
    int numberOfArea = 0;
    int maxSizeOfOneArea = 0;
    int M, N;
    
    public int[] solution(int m, int n, int[][] picture) {
        int[] answer = new int[2];
        M = m; N = n;
        
        // init
        matrix = new int[M][N];
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                matrix[i][j] = picture[i][j];
            }
        }
        
        // 모든 면을 살피면서, 0이 아니고 + 방문하지 않은 면 찾기
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (matrix[i][j] > 0) {
                    bfs(i, j, matrix[i][j]);
                    numberOfArea++;
                }
            }
        }
        
        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        
        return answer;
    }
    
    public void bfs(int r, int c, int color) {
        Queue<Point> q = new ArrayDeque<>();
        matrix[r][c] = 0;      // 방문 처리
        q.offer(new Point(r, c));
        
        int cnt = 1;
        Point cur;
        while (!q.isEmpty()) {
            cur = q.poll();
            for (int[] dir : dirs) {
                int nr = cur.x + dir[0];
                int nc = cur.y + dir[1];
                
                if (inBound(nr, nc) && matrix[nr][nc] == color) {
                    matrix[nr][nc] = 0;
                    q.offer(new Point(nr, nc));
                    cnt++;
                }
            }
        }
        
        maxSizeOfOneArea = Math.max(cnt, maxSizeOfOneArea);
    }
    
    public boolean inBound(int r, int c) {
        return r < M && r >= 0 && c < N && c >= 0;
    }
}