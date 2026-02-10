class Solution {
    int answer = 0;
    int N, M;
    int[][] matrix;
    boolean[] visited;
    
    public int solution(int k, int[][] dungeons) {
        N = dungeons.length;
        M = dungeons[0].length;
        matrix = new int[N][M];
        visited = new boolean[N];
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                matrix[i][j] = dungeons[i][j];
            }
        }
        
        // 최대 던전 찾기
        traverse(0, k);
        
        return answer;
    }
    
    void traverse(int cnt, int curTired) {
        answer = Math.max(cnt, answer);
        
        // 던전 들어가기
        for (int i = 0; i < N; i++) {
            if (curTired >= matrix[i][0] && !visited[i])  {
                visited[i] = true;
                traverse(cnt + 1, curTired - matrix[i][1]);
                visited[i] = false;
            }
        }
    }
}