import java.io.*;
import java.util.*;

class Main {
    static final int MAX = 100_000;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        // 조기 종료: 뒤로만 걸어가는 경우가 최적
        if (N >= K) {
            System.out.println(N - K);
            return;
        }

        int[] dist = new int[MAX + 1];
        Arrays.fill(dist, -1);

        ArrayDeque<Integer> q = new ArrayDeque<>();
        dist[N] = 0;
        q.offer(N);

        while (!q.isEmpty()) {
            int cur = q.poll();
            if (cur == K) {
                System.out.println(dist[cur]);
                return;
            }

            // 세 가지 이동
            int[] nexts = { cur - 1, cur + 1, cur * 2 };
            for (int nx : nexts) {
                if (0 <= nx && nx <= MAX && dist[nx] == -1) {
                    dist[nx] = dist[cur] + 1;
                    q.offer(nx);
                }
            }
        }
    }
}