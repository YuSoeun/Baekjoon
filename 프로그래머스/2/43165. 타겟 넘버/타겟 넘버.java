import java.io.*;

class Solution {
    int N, TARGET;
    int answer = 0;
    int matrix[][];
    
    public int solution(int[] numbers, int target) {
        TARGET = target;
        N = numbers.length;
        matrix = new int[2][N];
        
        int i = 0;
        for (int num : numbers) {
            matrix[0][i] = numbers[i];
            matrix[1][i] = -numbers[i];
            i++;
        }
        
        dfs(0, 0, 0);  // 처음에 0행 0열 선택
        // dfs(1, 0, matrix[0][1]);  // 처음에 1행 0열 선택
        
        return answer;
    }
    
    void dfs(int r, int c, int sum) {
        // System.out.println("r: " + r + ", c: " + c + ", sum " + sum);
        if (c == N && sum == TARGET) {
            answer++;
            return;
        }
        else if (c < N) {
            dfs(0, c+1, sum + matrix[0][c]);
            dfs(1, c+1, sum + matrix[1][c]);
        }
    }
}