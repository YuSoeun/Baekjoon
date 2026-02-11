class Solution {
    public int solution(int[][] sizes) {
        int answer = 0;
        int maxWidth = 1;
        int maxHeight = 1;
        
        // 가로 > 세로일 때 가로길이 max 값, 세로 길이 max 값 찾기
        for (int[] size : sizes) {
            maxWidth  = Math.max(maxWidth, Math.max(size[0], size[1]));
            maxHeight = Math.max(maxHeight, Math.min(size[0], size[1]));
        }
        
        answer = maxWidth * maxHeight;
        return answer;
    }
}