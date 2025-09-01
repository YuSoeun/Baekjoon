import java.util.*;
import java.io.*;

class Main {
    static int          N, K;
    static Queue<Point> q;
    static boolean[]    visited;
    
    static class Point {
        int distance;
        int index;
        
        Point(int distance, int index) {
            this.distance = distance;
            this.index = index;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        q = new LinkedList<Point>();
        visited = new boolean[100001];
        
        Point p = new Point(0, N);
        q.offer(p);
        visited[N] = true;
        while (!q.isEmpty()) {
            Point cur = q.poll();
            if (cur.index == K) {
                System.out.println(cur.distance);
                return;
            }
            
            if (1 + cur.index <= 100000 && !visited[cur.index+1]) {
                visited[cur.index+1] = true;
                q.offer(new Point(cur.distance+1, cur.index+1));
            }
            
            if (-1 + cur.index >= 0 && !visited[cur.index-1]) {
                visited[cur.index-1] = true;
                q.offer(new Point(cur.distance+1, cur.index-1));
            }
            
            if (2 * cur.index <= 100000 && !visited[cur.index*2]) {
                visited[cur.index*2] = true;
                q.offer(new Point(cur.distance+1, cur.index*2));
            }
        }
    }
}