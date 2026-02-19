import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N = Integer.parseInt(st.nextToken());
        int junhyen = N, junhyenCnt = 0;
        int sungmin = N, sungminCnt = 0;
        
        st = new StringTokenizer(br.readLine());
        int prev = 0;
        int cur = 0;
        int plus = 0;
        for (int i = 0; i < 14; i++) {
            cur = Integer.parseInt(st.nextToken());
            if (junhyen / cur > 0) {
                junhyenCnt += junhyen / cur;
                junhyen %= cur;
            }

            int increase = cur - prev;
            if (increase > 0) {
                if (plus <= 0)  plus = 1;
                else            plus++;
            } else if (increase < 0) {
                if (plus >= 0)  plus = -1;
                else            plus--;
            } else { 
                plus = 0;
            }
            
            if (plus >= 3) {
                sungmin += sungminCnt * cur;
                sungminCnt = 0;
            } else if (plus <= -3) {
                sungminCnt += sungmin / cur;
                sungmin %= cur;
            }
            prev = cur;
        }

        int jMoney = junhyen + cur * junhyenCnt;
        int sMoney = sungmin + cur * sungminCnt;
        if (jMoney > sMoney) {
            System.out.println("BNP");
        } else if (jMoney == sMoney) {
            System.out.println("SAMESAME");
        } else {
            System.out.println("TIMING");
        }
    }
}