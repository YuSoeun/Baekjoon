class Solution {
    char[] dict = {'A', 'E', 'I', 'O', 'U'};
    int[] weight;    // weight[0] = 5^4 + 5^3 + 5^2 + 5^1 + 5^0
    
    public int solution(String word) {
        int answer = 0;
        int N = 5;
        
        // 자리수별 가중치 계산
        weight = new int[5];
        for (int i = 0; i < N; i++) {
            for (int j = N-1-i; j >= 0; j--) {
                weight[i] += Math.pow(N, j);
            }
        }
        
        // 단어가 사전에서 몇 번째 단어
        answer += word.length();    // 각 자리에 알파벳이 있는 비용
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            for (int j = 0; j < dict.length; j++) {
                if (ch == dict[j]) {
                    answer += (weight[i] * j);
                    System.out.println(weight[i] + " " + j);
                }
            }
        }
        
        return answer;
    }
}