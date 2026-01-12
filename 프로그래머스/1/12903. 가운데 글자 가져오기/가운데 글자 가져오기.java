class Solution {
    public String solution(String s) {
        String answer = "";
        int num = 2 - s.length() % 2;
        
        int start = s.length()/2 - (s.length()+1)%2;
        answer = s.substring(start, start+num);
        
        return answer;
    }
}