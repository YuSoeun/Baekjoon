class Solution {
    public int solution(int[] mats, String[][] park) {
        int answer = -1;
        int maxMat = -1;
        int N = park.length;
        int M = park[0].length;
        int[][] matrix = new int[N][M];
        
        // 각 칸의 왼쪽에서 연속하여 빈 공간의 수를 저장
        for (int i = 0; i < N; i++) {
            int emptyCnt = 0;
           for (int j = 0; j < M; j++) {
               if ("-1".equals(park[i][j])) {
                   matrix[i][j] = ++emptyCnt;
               } else {
                   emptyCnt = 0;
               }
           }
        }
        
        // 가능한 매트의 최대 길이 계산
        // 1. 빈 칸을 찾으면 저장된 길이 저장(x), cnt=1
        // 2. 한 칸 아래로 내려가 저장된 길이  x 면 
        for (int i = 0; i < N; i++) {
            int prev = 0;
            int rowCnt = 0;

           for (int j = 0; j < M; j++) {
               if (matrix[i][j] > 0) {
                   prev = matrix[i][j];
                   rowCnt = 1;
                   maxMat = Math.max(maxMat, 1);
                   
                   while (i+rowCnt < N && prev > rowCnt) {
                       int index = i+rowCnt;
                        if (matrix[index][j] > rowCnt) {
                            prev = Math.min(prev, matrix[index][j]);
                            rowCnt++;
                            maxMat = Math.max(maxMat, Math.min(prev, rowCnt));
                       } else {
                            break;
                       }
                   }
               } else {
                   prev = 0;
                   rowCnt = 0;
               }
           }
        }
        
        // 가능한 매트 중 조건에 맞는 값 answer로
        for (int mat : mats) {
            if (mat <= maxMat) {
                answer = Math.max(mat, answer);
            }
        }
        
        return answer;
    }
}
