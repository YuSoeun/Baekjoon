import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static int[] matrix, nums;
	static boolean[] visited;
	static int N, M;
	static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		matrix = new int[N];
		visited = new boolean[N];
		nums = new int[M];
		for (int i = 0; i < N; i++) {
			matrix[i] = i+1;
		}
		
		perm(0);
		System.out.print(sb);
	}
	
	static void perm(int depth) {
		if (depth == M) {
			// base logic
			for (int e : nums) {
				sb.append(e + " ");
			}
			sb.append("\n");
			return;
		} else {
			for (int i = 0; i < N; i++) {
//				if (visited[i])
//					continue;
				
//				visited[i] = true;
				nums[depth] = matrix[i];
				
				perm(depth + 1);
				
//				visited[i] = false;
				nums[depth] = 0;

			}
		}
	}
}
