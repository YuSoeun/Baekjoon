import java.util.*;
import java.io.*;

public class Main {
    static int N, M;
    static Map<Integer, List<Node>> map;
    // 메모이제이션: memo[부품번호][기본부품번호] = 필요한 개수
    static int[][] memo;
    static boolean[] isBasic; // 기본 부품 여부 체크

    public static void main(String[] args) throws Exception {
        BufferedReader  br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        map = new HashMap<>();
        isBasic = new boolean[N + 1];
        Arrays.fill(isBasic, true); // 일단 모두 기본 부품이라고 가정
        visited = new boolean[N + 1];
        
        for (int i = 1; i <= N; i++) {
            map.put(i, new ArrayList<Node>());
        }

        for (int i = 0; i < M; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int X = Integer.parseInt(st.nextToken());
            int Y = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());
            map.get(X).add(new Node(Y, K, false));
            isBasic[X] = false;
        }
        
        memo = new int[N + 1][N + 1];
        int[] finalCounts = getCounts(N);

        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= N; i++) {
            if (isBasic[i] && finalCounts[i] > 0) {
                sb.append(i).append(" ").append(finalCounts[i]).append("\n");
            }
        }
        System.out.print(sb);
    }

    static boolean[] visited;
    static int[] getCounts(int target) {
        if (isBasic[target]) {
            int[] res = new int[N + 1];
            res[target] = 1;
            return res;
        }

        if (visited[target]) return memo[target];

        visited[target] = true;
        for (Node node : map.get(target)) {
            int[] subCounts = getCounts(node.component.number);

            for (int i = 1; i <= N; i++) {
                if (subCounts[i] > 0) {
                    memo[target][i] += subCounts[i] * node.component.count;
                }
            }
        }

        return memo[target];
    }

    static class Component {
        int number;
        int count;
        public Component(int x, int y) {
            number = x;
            count  = y;
        }
    };

    static class Node {
        Component component;
        boolean hasOnlyBasic = false;

        public Node(int x, int y, boolean z) {
            component = new Component(x, y);
            hasOnlyBasic = z;
        }
    };
}