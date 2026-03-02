import java.util.*;
import java.io.*;

public class Main {
    static int N;   // 사람의 수
    static int M;   // 파티의 수
    static int T;   // 진실을 아는 사람 수
    static int[] p;
    static int[] truth; // 진실을 아는 사람
    
    public static void main(String[] args) throws Exception {
        BufferedReader  br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        // 사람의 수
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        p = new int[N+1];
        for (int i = 1; i < N+1; i++) {
            p[i] = i;
        }

        // 진실을 아는 사람
        st = new StringTokenizer(br.readLine());
        T = Integer.parseInt(st.nextToken());
        truth = new int[T];
        for (int i = 0; i < T; i++) {
            truth[i] = Integer.parseInt(st.nextToken());
        }

        // 각 파티에
        List<Integer> partyJang = new ArrayList<>();
        for (int m = 1; m < M+1; m++) {
            st = new StringTokenizer(br.readLine());
            int K = Integer.parseInt(st.nextToken());

            // 오는 사람들의 번호 (1부터 시작)
            int from = Integer.parseInt(st.nextToken());
            partyJang.add(from);
            for (int k = 2; k < K+1; k++) {
                int to = Integer.parseInt(st.nextToken());
                union(from, to);
            }
        }

        int answer = 0;
        // 진실을 모르는 사람만 있는 파티 개수 구하기 visited 사용
        for (int jang : partyJang) {
            boolean isValid = true;
            for (int e : truth) {
                if (find(e) == find(jang)) {
                    isValid = false;
                    break;
                }
            }
            if (isValid)  answer++;
        }

        System.out.println(answer);
    }

    static void union(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb) { // 다르면 합친다.
            p[pb] = pa;
        }
    }

    static int find(int x) {
        if (p[x] != x) {
            return p[x] = find(p[x]);
        }
        return p[x];
    }
}