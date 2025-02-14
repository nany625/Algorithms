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
        int ans = 0;
        for(int i = 2; i <= n; ++i)
            ans = (ans + k) % i;
        return ans;
    }
}
