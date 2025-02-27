import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_WORD) {
            String X = st.sval;
            st.nextToken();
            String Y = st.sval;
            output.append("Length of LCS of strings \"").append(X).append("\" and \"").append(Y).append("\": ").append(lengthOfLCS(X, Y)).append('\n');
        }
        System.out.print(output);
	}
	
	static int lengthOfLCS(String X, String Y) {
        int[] dp = new int[Y.length() + 1];
        for(int i = 0; i < X.length(); ++i) {
            int prev = 0;
            for(int j = 1; j <= Y.length(); ++j) {
                int temp = dp[j];
                if(X.charAt(i) == Y.charAt(j - 1))
                    dp[j] = prev + 1;
                else
                    dp[j] = Math.max(dp[j], dp[j - 1]);
                prev = temp;
            }
        }
        return dp[Y.length()];
    }
}
