import java.io.*;
import java.util.*;

public class Main {
    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        String next() { // reads in the next string
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        } // reads in the next int

        public long nextLong() {
            return Long.parseLong(next());
        } // reads in the next long

        public double nextDouble() {
            return Double.parseDouble(next());
        } // reads in the next double
    }

    static InputReader f = new InputReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        // YOUR CODE HERE //! @ % & * () _ {} # ~ : < > ? "" | ^
        int n = f.nextInt();
        int ans = 1;
        List<int[]> arr = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            int l, r;
            l = f.nextInt();
            r = f.nextInt();
            arr.add(new int[] { l, r });
        }

        arr.sort(Comparator.comparingInt(a -> a[1]));

        int j = 0;
        for (int i = 1; i < n; ++i) {
            if (arr.get(i)[0] >= arr.get(j)[1]) {
                j = i;
                ++ans;
            }
        }
        out.println(ans);

        out.close(); // flushes the output once printing is done
    }
}