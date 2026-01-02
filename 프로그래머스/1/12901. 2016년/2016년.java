class Solution {
    String[] day = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int[] month = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    public String solution(int a, int b) {
        String answer = "";
        int dayCnt = b+4;  // 금요일 더하기
        
        // 일 수 계산
        for (int i = 0; i < a-1; i++) {
           dayCnt += month[i];
        }
        System.out.println(dayCnt);
        
        // 7로 나눈 나머지 저장
        answer = day[dayCnt % 7];
        
        // 최종 요일 계산
        return answer;
    }
}