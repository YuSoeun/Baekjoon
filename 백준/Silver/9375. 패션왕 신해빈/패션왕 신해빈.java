import java.util.*;
import java.util.Map.*;
import java.io.*;

public class Main {
    static int  T, N;
    
    public static void main(String[] args) throws Exception {
        BufferedReader  br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        T = Integer.parseInt(st.nextToken());

        // 입을 수 있는 옷의 조합
        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());

            Map<String, Integer> m = new HashMap<>();
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                String value = st.nextToken();
                String key = st.nextToken();
                m.put(key, m.getOrDefault(key, 0) + 1);
            }

            int answer = 1;
            // Case 1:
            // 3(type1에서 0~2개 선택) * 2(type2에서 0~1개 선택) - 1(0개 선택은 없음)
            // Case 2:
            // 4(type1에서 0~3개 선택) - 1(0개 선택은 없음)
            for (Entry<String, Integer> entry : m.entrySet()) {
                answer *= (entry.getValue() + 1);
            }
            answer -= 1;
            sb.append(answer).append("\n");
        }
        System.out.print(sb);
    }
}