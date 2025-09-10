import java.io.*;
import java.util.*;

public class Main_16987_계란으로계란치기 {
    static int N;
    static int result = 0;
    static int cnt    = 0;
    static int[] Duration, Weight;

    static void backtracking(int cur, int target) {
        // 만약 끝까지 갔거나 cur이 깨지면, cur++을 cur의 내구도가 0이 아닐 때까지 하고, target를 cur+1로
        System.out.println(cur + " " + target);

        if (target >= N) {
            while ()
        }
        if (Duration[cur] <= 0) {
            while (++cur < N-1 && Duration[cur] <= 0);
            // cur이 범위 초과하면 저장
            if (cur >= N-1) {
                cnt = 0;
                System.out.print("Duration: ");
                for (int d : Duration) {
                    System.out.print(d + " ");
                    if (d <= 0)   cnt++;
                }
                System.out.println("\n----> " + cnt);
                result = Math.max(result, cnt);
                return;
            }
            target = cur + 1;
        }

        System.out.println(cur + " " + target);

        // cur로 계란 target을 친다
        if (Duration[target] > 0) {
            Duration[target] -= Weight[cur];
            Duration[cur]    -= Weight[target];
            backtracking(cur, target+1);

            // 안치고 target++한다.
            Duration[target] += Weight[cur];
            Duration[cur]    += Weight[target];
            backtracking(cur, target+1);
        } else {
            backtracking(cur, target+1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        Duration = new int[N];
        Weight   = new int[N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            Duration[i] = Integer.parseInt(st.nextToken());
            Weight[i]   = Integer.parseInt(st.nextToken());
        }
        backtracking(0, 1);
        System.out.println(result);
    }
}