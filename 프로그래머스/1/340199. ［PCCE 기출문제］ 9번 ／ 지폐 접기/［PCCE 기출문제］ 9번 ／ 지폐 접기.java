class Solution {
    public int solution(int[] wallet, int[] bill) {
        int answer = 0;
        int minBill = Math.min(bill[0], bill[1]);;
        int maxBill = Math.max(bill[0], bill[1]);;
        int minWallet = Math.min(wallet[0], wallet[1]);
        int maxWallet = Math.max(wallet[0], wallet[1]);
        
        while (minBill > minWallet || maxBill > maxWallet) {
            maxBill /= 2;
            answer++;
            
            int temp = maxBill;
            maxBill = Math.max(maxBill, minBill);
            minBill = Math.min(temp, minBill);
        }
        
        return answer;
    }
}