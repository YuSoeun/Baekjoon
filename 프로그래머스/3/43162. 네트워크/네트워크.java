import java.util.*;

class Solution {
    int N;
    int matrix[][];
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        N = n;
        matrix = new int[n][n];
        
        // 1. 컴퓨터 있는 위치 1 -> -1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (computers[i][j] == 1) {
                    matrix[i][j] = -1;
                    matrix[j][i] = -1;
                }
            }
        }
        
        // 2. 방문하지 않은 노드 1개 선정
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1) {
                    // 3. 인접한 노드 방문하며 -1 -> network_cnt
                    bfs(++answer, i, j);
                }
            }
        }
        
        return answer;
    }
    
    class Point {
        int r;
        int c;
        public Point(int x, int y) {
            r = x;
            c = y;
        }
    }
    
    int[][] dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    void bfs(int netCnt, int r, int c) {
        ArrayDeque<Point> q = new ArrayDeque<>();
        matrix[r][c] = netCnt;
        matrix[c][r] = netCnt;
        q.offer(new Point(r, c));
        
        while (!q.isEmpty()) {
            Point cur = q.pop();
            for (int rCon = 0; rCon < N; rCon++) {
                if (matrix[cur.r][rCon] == -1) {
                    matrix[cur.r][rCon] = netCnt;
                    matrix[rCon][cur.r] = netCnt;
                    q.add(new Point(rCon, cur.r));
                }
            }
            
            for (int cCon = 0; cCon < N; cCon++) {
                if (matrix[cur.c][cCon] == -1) {
                    matrix[cur.c][cCon] = netCnt;
                    matrix[cCon][cur.c] = netCnt;
                    q.add(new Point(cCon, cur.c));
                }
            }
        }
    }
    
    boolean inBound(int r, int c) {
        return r >= 0 && r < N && c >= 0 && c < N;
    }
}