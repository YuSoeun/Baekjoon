import java.io.*;
import java.util.*;

// 1시간 걸린 문제: 위상 정렬을 잘 몰랐었네. (답 보고 품)

public class Main {
    static int T;                       // 테스트케이스의 수
    static int N;                       // 건물의 수
    static int K;                       // 규칙의 총 개수
    static int W;                       // target
    static int[] D;                     // 건설 시간
    static int[] indegree;              // 진입 차수
    static int[] result;                // 최소 건설 시간
    static ArrayList<Integer>[] adj;    // 인접 리스트
    @SuppressWarnings("unchecked")

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        T = Integer.parseInt(st.nextToken());

        for (int tc = 0; tc < T; tc++) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());

            D = new int[N];
            indegree = new int[N];
            result = new int[N];
            adj = new ArrayList[N];

            for (int i = 0; i < N; i++) {
                adj[i] = new ArrayList<>();
            }

            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                D[i] = Integer.parseInt(st.nextToken());
            }

            for (int i = 0; i < K; i++) {
                st = new StringTokenizer(br.readLine());
                int X = Integer.parseInt(st.nextToken()) - 1;
                int Y = Integer.parseInt(st.nextToken()) - 1;
                adj[X].add(Y);
                indegree[Y]++;
            }

            st = new StringTokenizer(br.readLine());
            W = Integer.parseInt(st.nextToken()) - 1;

            // 위상 정렬 수행
            Queue<Integer> q = new LinkedList<>();
            for (int i = 0; i < N; i++) {
                if (indegree[i] == 0) {
                    q.add(i);
                    result[i] = D[i];
                }
            }

            while (!q.isEmpty()) {
                int cur = q.poll();

                for (int next : adj[cur]) {
                    indegree[next]--;
                    result[next] = Math.max(result[next], result[cur] + D[next]);
                    if (indegree[next] == 0) {
                        q.add(next);
                    }
                }
            }

            System.out.println(result[W]);
        }
    }
}