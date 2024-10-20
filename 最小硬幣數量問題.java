import java.io.*;
import java.util.*;

public class Main {
    static int MAX_AMOUNT = 100000;
    static int[] dp = new int[MAX_AMOUNT + 1];
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        ArrayList<Integer> coins = new ArrayList<>();
        int value;
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (value = (int)st.nval) != 0)
            coins.add(value);
        for(int i = 1; i <= MAX_AMOUNT; ++i) {
            dp[i] = MAX_AMOUNT + 1;
            for(Integer j : coins) {
                if(i >= j)
                    dp[i] = Math.min(dp[i], dp[i - j] + 1);
            }
        }
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int amount = (int)st.nval;
            if(dp[amount] <= MAX_AMOUNT)
                output.append("Minimum coins required to make $").append(amount).append(": ").append(dp[amount]).append('\n');
            else
                output.append("It's not possible to make $").append(amount).append(" with the given coins.\n");
        }
        System.out.print(output);
	}
}
