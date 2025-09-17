import java.io.*;
import java.util.*;

public class Main_1629_multifly {
    static long A, B, C;
    static List<Long> twoPower;

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        twoPower = new ArrayList<>();

        A = Long.parseLong(st.nextToken());
        B = Long.parseLong(st.nextToken());
        C = Long.parseLong(st.nextToken());

        int x = 1;          // A to the Power of (2 to the Power of x)
        long pow = 2;       // 2 to the Power of x
        
        // set twoPower
        twoPower.add(A % C);
        while (pow <= B) {
            twoPower.add((twoPower.get(x-1) * twoPower.get(x-1)) % C);
            pow *= 2;
            x++;
        }

        long result = 1;
        for (int i = 0; i < twoPower.size(); i++) {
            if ((B & 1) == 1) {
                result = (result * twoPower.get(i)) % C;
            }
            B >>= 1;
        }
        System.out.println(result);
    }
}
