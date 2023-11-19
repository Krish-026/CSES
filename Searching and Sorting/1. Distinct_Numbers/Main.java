import java.io.*;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.HashSet;
public class Main {
    public static void main(String[] args) {
        IO io = new IO();
        int n = io.nextInt(); // Reads the next int separated by spaces.
        Set<Integer> set = new HashSet<>();
        for(int i = 0; i < n; ++i){
            set.add(io.nextInt());
        }
        io.println(set.size());
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