import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int drplus[][] = {{1, 0}, {0, 1}, {1, 1}, {-1, 1}};
	static int N = 19;
	static int matrix[][];
	
	static boolean inBound(int r, int c) {
		return r >= 0 && c >= 0 && r < N && c < N;
	}
	
	static boolean checkStone(int r, int c) {
		for (int dir[] : drplus) {
			if (dir[0] == 1 && dir[1] == 0 && c == 0 && r != 0)
				continue;
			if (dir[0] == 0 && dir[1] == 1 && r == 0 && c != 0)
				continue;
			if (dir[0] == 0 && dir[1] == 1 && r == N-1 && c != 0)
				continue;
			int nextR = r;
			int nextC = c;
			int oneCnt = 0, twoCnt = 0;
//			System.out.println(dir[0] + " " + dir[1]);
			
			while (inBound(nextR, nextC)) {
				if (matrix[nextR][nextC] == 1) {
					oneCnt++;
					twoCnt = 0;
				} else if (matrix[nextR][nextC] == 2) {
					twoCnt++;
					oneCnt = 0;
				} else {
					twoCnt = 0;
					oneCnt = 0;
				}
//				System.out.println("(" + nextR + ", " + nextC + ") " + matrix[nextR][nextC] + " | " + "1: " + oneCnt + ", 2: " + twoCnt);
				nextR += dir[0];
				nextC += dir[1];
				
				if (oneCnt == 5 && (!inBound(nextR, nextC) || matrix[nextR][nextC] != 1)) {
					System.out.println(1);
					System.out.println((nextR - dir[0]*5 + 1) + " " + (nextC - dir[1]*5 + 1));
					
					return true;
				} else if (twoCnt == 5 && (!inBound(nextR, nextC) || matrix[nextR][nextC] != 2)) {
					System.out.println(2);
					System.out.println((nextR - dir[0]*5 + 1) + " " + (nextC - dir[1]*5 + 1));
					
					return true;
				}
			}
		}
		
		return false;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		matrix = new int[N][N];
		
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				matrix[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		// C = 0
		for (int i = 0; i < N; i++) {
			if (checkStone(i, 0)) {
				return;
			}
		}
				
		// R = 0
		for (int i = 0; i < N; i++) {
			if (checkStone(0, i)) {
				return;
			}
		}
		
		// R = N-1
		for (int i = 0; i < N; i++) {
			if (checkStone(N-1, i)) {
				return;
			}
		}
		
		System.out.println(0);
	}
}