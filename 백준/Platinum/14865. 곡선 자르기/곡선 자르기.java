import java.io.*;
import java.util.*;

public class Main {
    static class Point implements Comparable<Point> {
        long x;
        boolean isStart;

        public Point(long x, boolean isStart) {
            this.x = x;
            this.isStart = isStart;
        }

        @Override
        public int compareTo(Point o) {
            return Long.compare(this.x, o.x);
        }
    }

    static class Pair {
        long x;
        long y;

        public Pair(long x, long y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        List<Pair> points = new ArrayList<>();
        List<Point> parentheses = new ArrayList<>();
        long firstX = Long.MAX_VALUE, firstY = Long.MAX_VALUE;
        int LDindex = 0;

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long x = Long.parseLong(st.nextToken());
            long y = Long.parseLong(st.nextToken());
            points.add(new Pair(x, y));

            // 가장 왼쪽 아래 점
            if (firstX > x || (firstX == x && firstY > y)) {
                firstX = x;
                firstY = y;
                LDindex = i;
            }
        }

        // 마지막 점과 첫 번째 점 사이의 교차 여부 확인
        int index = LDindex;
        int isUpper = 0;
        long left = 0;   // 왼쪽 봉우리 x 좌표
        while ((index + 1) % N != LDindex) {
            int nexti = (index + 1) % N;
            Pair cur = points.get(index);
            Pair next = points.get(nexti);

            // overflow 방지, 봉우리 앞 부분
            if (cur.x == next.x && ((cur.y > 0) ? 1 : -1) * next.y < 0) {
                if (cur.y < next.y) {
                    isUpper = 1;
                    left = cur.x;
                } else {
                    parentheses.add(new Point(Math.min(cur.x, left), true));
                    parentheses.add(new Point(Math.max(cur.x, left), false));
                    isUpper = 0;
                }
            }
            index = nexti;
        } 

        // x좌표 기준 정렬
        Collections.sort(parentheses);

        // 괄호 세기
        int pCnt = 0;
        int containCnt = 0;         // 다른 봉우리에 의해 포함되지 않는 봉우리 수
        int soloCnt = 0;            // 다른 봉우리를 포함하지 않는 봉우리의 수
        boolean prev = false;
        Stack<Integer> s = new Stack<>();
        for (Point m : parentheses) {
            // System.out.println("Seeing: " + m.x + " " + m.isStart);
            if (m.isStart) {
                s.add(pCnt);
                pCnt++;
            } else {
                s.pop();
                pCnt--;
                if (s.isEmpty()) {
                    containCnt++;
                }
                if (prev == true) {
                    soloCnt++;
                }
            }
            prev = m.isStart;
        }

        System.out.println(containCnt + " " + soloCnt);
    }
}