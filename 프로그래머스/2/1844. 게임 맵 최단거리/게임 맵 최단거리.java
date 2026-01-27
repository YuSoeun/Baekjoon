import java.io.*;
import java.util.*;

class Solution {
    int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int R, C;
    
    public int solution(int[][] maps) {
        int answer = -1;
        R = maps.length;
        C = maps[0].length;
        int r = 0;
        int c = 0;
        
        Queue<Point> q = new ArrayDeque<>();
        Point startPoint = new Point(r, c, 1);
        q.offer(startPoint);
        
        while (!q.isEmpty()) {
            Point cur = q.poll();
            // System.out.println(cur.r + " " + cur.c + " " + cur.cnt);
            if (cur.r == R-1 && cur.c == C-1) {
                return cur.cnt;
            }
            
            for (int dir[] : dirs) {
                int nr = cur.r + dir[0];
                int nc = cur.c + dir[1];
                int nCnt = cur.cnt + 1;
            
                if (isValid(nr, nc) && maps[nr][nc] == 1) {
                    maps[nr][nc] = 0;
                    Point newPoint = new Point(nr, nc, nCnt);
                    q.offer(newPoint);
                }
            }
        }
        
        return answer;
    }
    
    class Point {
        int r;
        int c;
        int cnt;
        
        public Point(int x, int y, int z) {
            r = x;
            c = y;
            cnt = z;
        }
    }
    
    boolean isValid(int r, int c) {
        return r < R && r >= 0 && c < C && c >= 0;
    }
}