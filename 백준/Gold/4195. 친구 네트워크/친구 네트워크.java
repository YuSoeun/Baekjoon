import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    static int[] parent, size;
    static HashMap<String, Integer> map;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            int F = Integer.parseInt(br.readLine());
            parent = new int[2 * F + 1];
            size = new int[2 * F + 1];
            map = new HashMap<>();

            for (int i = 0; i < 2 * F + 1; i++) {
                parent[i] = i;
                size[i] = 1;
            }

            int index = 0;
            for (int i = 0; i < F; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                String s1 = st.nextToken();
                String s2 = st.nextToken();

                if (!map.containsKey(s1)) map.put(s1, index++);
                if (!map.containsKey(s2)) map.put(s2, index++);

                int a = map.get(s1);
                int b = map.get(s2);

                sb.append(union(a, b)).append("\n");
            }
        }
        System.out.println(sb);
    }

    private static int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    // 유니온 연산 + 네트워크 크기 반환
    private static int union(int a, int b) {
        a = find(a);
        b = find(b);

        if (a != b) {
            if (size[a] < size[b]) {    // 작은 트리를 큰 트리에 합침
                int temp = a;
                a = b;
                b = temp;
            }
            parent[b] = a;
            size[a] += size[b];         // 네트워크 크기 업데이트
        }
        return size[a];
    }
}