import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int T, A, B;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        T = Integer.parseInt(st.nextToken());

        for (int t = 1; t <= T; t++) {
            st = new StringTokenizer(br.readLine());
            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());
            int result = A % 10;

            for (int i = 1; i < B; i++) {
                result = (result * A) % 10;
            }
            if (result == 0) {
                System.out.println("10");
            } else {
                System.out.println(result);
            }
        }
    }
}