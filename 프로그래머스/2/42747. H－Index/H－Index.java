class Solution {
    int[] array;
    int answer;
    public int solution(int[] citations) {
        answer = 0;
        array = new int[citations.length];
        int i = 0;
        for (int c : citations) {
            array[i++] = c;
        }
        
        // 과학자의 H-index의 최댓값
        binary_search(0, 10000);
        
        return answer;
    }
    
    void binary_search(int start, int end) {
        while (start <= end) {   // 확인
            int mid = (start + end) / 2;
            // System.out.println("mid: " + mid);
            if (isValid(mid)) {
                answer = Math.max(answer, mid);
                start = mid+1;
            } else {
                end = mid-1;
            }
        }
    }
    
    boolean isValid(int h) {
        int count = 0;
        for (int e : array) {
            if (e >= h) count++;
            if (count >= h) return true;
        }
        return false;
    }
}