/*
 * 비밀번호를 찾는 프로그램
 * N(1 ≤ N ≤ 100,000): 사이트 주소의 수
 * M(1 ≤ M ≤ 100,000): 비밀번호를 찾으려는 사이트 주소의 수
 * N개 - 사이트 주소(알파벳 소/대문자, '-', '.' 중복 X) 비밀번호 (대문자, 20자)
 */

import java.util.*;
import java.io.*;

public class Main {
    static int N, M;
    static Map <String, String> map;

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new TreeMap<>();

        String site, pass;
        StringBuffer sb = new StringBuffer();
        while (N-- > 0) {
            st = new StringTokenizer(br.readLine());
            site = st.nextToken();
            pass = st.nextToken();
            map.put(site, pass);
        }

        while (M-- > 0) {
            st = new StringTokenizer(br.readLine());
            site = st.nextToken();
            sb.append(map.get(site) + '\n');
        }

        System.out.print(sb);
    }
}