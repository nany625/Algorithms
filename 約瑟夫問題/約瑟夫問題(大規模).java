import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            long n = (long)st.nval;
            st.nextToken();
            long k = (long)st.nval;
            output.append("The last person standing is at position ").append(josephus(n, k) + 1).append('\n');
        }
        System.out.print(output);
    }
    
    static long josephus(long n, long k) {
        if(n == 1)
            return 0;
        if(k == 1)
            return n - 1;
        if(k > n)
            return (josephus(n - 1, k) + k) % n;
        long ans = josephus(n - n / k, k);
        ans -= n % k;
        if(ans < 0)
            ans += n;
        else
            ans += ans / (k - 1);
        return ans;
    }
}
