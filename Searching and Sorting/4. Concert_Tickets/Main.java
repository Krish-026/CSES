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
        int m = f.nextInt();
        int x = 0;

        TreeMap<Integer, Integer> map = new TreeMap<>();
        for (int i = 0; i < n; i++) {
            x = f.nextInt();
            if (map.containsKey(x)) {
                map.put(x, map.get(x) + 1);
            } else
                map.put(x, 1);
        }

        for (int i = 0; i < m; i++) {
            x = f.nextInt();
            int freq = 0;

            if (map.containsKey(x)) {
                freq = map.get(x);
                if (freq > 0) {
                    out.println(x);
                    map.put(x, --freq);

                    if (freq == 0) {
                        map.remove(x);
                    }
                    continue;
                }

            }

            else if (map.lowerKey(x) != null) {
                int val = map.lowerKey(x);
                freq = map.get(val);
                if (freq > 0) {
                    out.println(val);
                    map.put(val, --freq);

                    if (freq == 0) {
                        map.remove(val);
                    }
                    continue;
                }
            }
            out.println(-1);
        }

        out.close(); // flushes the output once printing is done
    }
}