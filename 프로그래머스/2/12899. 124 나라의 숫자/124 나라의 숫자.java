class Solution {
    static int[] oneTwoFour = {4, 1, 2};
    
    public String solution(int n) {
        long answer = 0;
        long multi   = 1;
        
        while (n > 0) {
            answer += oneTwoFour[n % 3] * multi;
            if (n % 3 == 0) {
                n = n / 3 - 1;
            } else {
                n /= 3;
            }
            multi *= 10;
        }
        
        return Long.toString(answer);
    }
}