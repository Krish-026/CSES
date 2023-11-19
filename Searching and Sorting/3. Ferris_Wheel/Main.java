import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        IO io = new IO();
        int n = io.nextInt();
        int w = io.nextInt();
        int wgh[] = new int[n];
        for (int i = 0; i < n; ++i) {
            wgh[i] = io.nextInt();
        }
        int i = 0, j = n - 1, ans = 0;
        Arrays.sort(wgh);
        while (i <= j) {
            if (wgh[i] + wgh[j] <= w) {
                ++i;
                --j;
            } else {
                --j;
            }
            ++ans;
        }
        System.out.println(ans);
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
