import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main
{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuffer sb = new StringBuffer();
        int cur;

        int T = Integer.parseInt(st.nextToken());
        for (int i = 0; i < T; i++) {
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int max = -1_000_000;
            int min = 1_000_000;

            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                cur = Integer.parseInt(st.nextToken());
                max = Math.max(max, cur);
                min = Math.min(min, cur);
            }
            sb.append(min + " " + max + "\n");
        }

        System.out.println(sb);
    }
}