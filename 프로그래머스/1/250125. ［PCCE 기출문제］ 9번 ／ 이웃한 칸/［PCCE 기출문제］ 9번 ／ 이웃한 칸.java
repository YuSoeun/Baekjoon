class Solution {
    int R, C;
    int dirs[][] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    public int solution(String[][] board, int h, int w) {
        int answer = 0;
        R = board.length;
        C = board[0].length;
        
        int h_check, w_check;
        for (int dir[] : dirs) {
            h_check = h + dir[0];
            w_check = w + dir[1];
            
            if (isValid(h_check, w_check) && board[h][w].equals(board[h_check][w_check])) {
            System.out.println(board[h][w] + " " + board[h_check][w_check]);
                answer++;
            }
        }
        
        return answer;
    }
    
    boolean isValid(int r, int c) {
        return r < R && r >= 0 && c < C && c >= 0;
    }
}