import java.lang.*;
import java.io.*;

public class Main_1629_multifly {
    static Long A, B, C;
    static Long twoPower[];

    public static void main(String args[]) throws Exception {
        Bufferedreader br = new BufferedReader(new inputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        int x = 1;  // A to the Power of (2 to the Power of x)
        
        // set twoPower
        twopower[0] = A % C;
        while (x <= B) {
            twoPower[x] = twoPower[x-1] * twoPower[x-1] % C;
            x++;
        }

        int result = 0;
        while (1)
    }
}
