import java.io.*;
import java.util.*;

public class Main {
    static int MAX_TARGET = 100000;
    static long[] dp = new long[MAX_TARGET + 1];
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        ArrayList<Integer> coins = new ArrayList<>();
        int value;
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (value = (int)st.nval) != 0)
            coins.add(value);
        dp[0] = 1;
        for(Integer i : coins) {
            for(int j = i; j <= MAX_TARGET; ++j)
                dp[j] += dp[j - i];
        }
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int target = (int)st.nval;
            output.append("Number of combinations to make $").append(target).append(": ").append(dp[target]).append('\n');
        }
        System.out.print(output);
	}
}
