import java.util.*;
import java.io.*;

public class Main {
    static int N, L;
    static int[] size;
    static int[] p;
    
    public static void main(String[] args) throws Exception {
        BufferedReader  br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder   sb = new StringBuilder();
        
        // init
        N = Integer.parseInt(st.nextToken());
        L = Integer.parseInt(st.nextToken());
        
        size = new int[L+1];
        p = new int[L+1];

        Arrays.fill(size, 1);
        for (int i = 1; i <= L; i++) {
            p[i] = i;
        }

        // solution
        int A, B;
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());

            union(A, B);

            int root = find(A);
            if (size[root] > 0) {
                size[root]--;
                sb.append("LADICA").append("\n");
            } else {
                sb.append("SMECE").append("\n");
            }
        }

        System.out.print(sb);
    }

    static void union(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa != pb) {
            p[pb] = pa;
            size[pa] += size[pb];
        }
    }

    static int find(int x) {
        if (x != p[x]) {
            return p[x] = find(p[x]);
        }
        return x;
    }
}