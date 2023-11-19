import java.io.*;
import java.util.StringTokenizer;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        IO io = new IO();
        int n = io.nextInt();
        int m = io.nextInt();
        int k = io.nextInt();
        int[] desired = new int[n];
        int[] apartments = new int[m];
        for(int i = 0; i < n; ++i){
            desired[i] = io.nextInt();
        }
        for(int i = 0; i < m; ++i){
            apartments[i] = io.nextInt();
        }
        Arrays.sort(desired);
        Arrays.sort(apartments);
        int i = 0, j = 0, count = 0;
        while(i < n && j < n){
            if(Math.abs(desired[i] - apartments[j]) <= k){
                ++i;
                ++j;
                ++count;
            }
            else if(desired[i] < apartments[j]){
                ++i;
            }
            else{
                ++j;
            }
        }
        io.println(count);
        io.close(); 
    }
}

class IO {
    private BufferedReader br;
    private PrintWriter pw;
    private StringTokenizer st;

    public IO() {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    }

    public String next() {
        while (st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public void print(Object obj) {
        pw.print(obj);
    }

    public void println(Object obj) {
        pw.println(obj);
    }

    public void close() {
        pw.close();
    }
}