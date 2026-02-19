import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // 일정이 있는 곳에만 코팅지 붙이기
        // 연속된 모든 일정은 하나의 직사각형에 포함
        int[] calendar = new int[366];

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());

            for (int j = from; j <= to; j++) {
                calendar[j]++;
            }
        }

        int answer = 0;
        int width  = 0; // 코팅지 가로 길이
        int height = 0; // 코팅지 높이 = max
        for (int i = 1; i <= 365; i++) {
            if (calendar[i] == 0) {
                answer += width * height;
                width = 0;
                height = 0;
            } else {
                width++;
                height = Math.max(height, calendar[i]);
            }
        }
        answer += width * height; // 생각!

        System.out.println(answer);
    }
}
