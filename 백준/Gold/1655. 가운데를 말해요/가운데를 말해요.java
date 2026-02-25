import java.util.*;
import java.io.*;

public class Main {
    static int N;
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        PriorityQueue<Integer> rightPQ = new PriorityQueue<>(); // 1 2 3
        PriorityQueue<Integer> leftPQ = new PriorityQueue<>(Collections.reverseOrder()); // 3 2 1

        N = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int num = Integer.parseInt(st.nextToken());

            if (leftPQ.isEmpty() || num <= leftPQ.peek()) {
                leftPQ.offer(num);
            } else {
                rightPQ.offer(num);
            }

            if (leftPQ.size() < rightPQ.size()) {
                leftPQ.offer(rightPQ.poll());
            } else if (leftPQ.size() > rightPQ.size() + 1) {
                rightPQ.offer(leftPQ.poll());
            }
            
            sb.append(leftPQ.peek()).append("\n");
        }
        System.out.print(sb);
    }
}