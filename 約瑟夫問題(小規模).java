import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int n = (int)st.nval;
            st.nextToken();
            int k = (int)st.nval;
            output.append("The last person standing is at position ").append(josephus(n, k) + 1).append('\n');
        }
        System.out.print(output);
    }
    
    static int josephus(int n, int k) {
        return n == 1 ? 0 : (josephus(n - 1, k) + k) % n;
    }
}
