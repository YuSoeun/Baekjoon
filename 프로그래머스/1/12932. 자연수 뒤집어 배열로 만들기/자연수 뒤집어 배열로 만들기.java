class Solution {
    public int[] solution(long n) {
        int[] answer = {};
        String s = Long.toString(n);
        int N = s.length();
        
        answer = new int[N];
        for (int i = 0; i < N; i++) {
            answer[i] = s.charAt(N-1-i) - '0';
        }
        
        return answer;
    }
}