import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static int N;
	static int[][] map;
	static int[][] visited;
	static int[] dr = {-1, 0, 1, 0};
	static int[] dc = {0, -1, 0, 1};
	static int num = 0;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		map = new int[N][N];
		visited = new int[N][N];
		
		for (int i = 0; i < N; i++) {
			char[] cst = br.readLine().toCharArray();
			for (int j = 0; j < N; j++) {
				map[i][j] = cst[j] - '0';
			}
		}
		int[] houseCnt = new int[N*N];
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 1) {
					num = 1;
					cnt++;
					dfs(i, j, cnt+1);
					houseCnt[cnt-1] = num;
					
				}
			}
		}
		Arrays.sort(houseCnt);
		System.out.println(cnt);
		for (int e : houseCnt) {
			if (e != 0) {
				System.out.println(e);
			}
		}
	}

	
	private static void dfs(int r, int c, int g) {
		map[r][c] = g;
		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			
			if (!check(nr, nc)) continue;
			if (map[nr][nc] == 1) {
				dfs(nr, nc, g);
				num++;
			}
		}
	}
	
	public static boolean check(int r, int c) {
		return r >= 0 && r < N && c >= 0 && c < N;
	}
}
