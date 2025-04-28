import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static PriorityQueue<Integer> pq = new PriorityQueue<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            pq.offer(Integer.parseInt(st.nextToken()));
        }

        int result = 0;
        while (!pq.isEmpty() && pq.size() != 1) {
            int sum = pq.poll() + pq.poll();
            result += sum;

            if (!pq.isEmpty()) {
                pq.offer(sum);
            }
        }

        System.out.println(result);
    }
}