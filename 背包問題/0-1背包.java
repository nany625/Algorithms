import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int n = (int)st.nval;
        Item[] items = new Item[n];
        for(int i = 0; i < n; ++i) {
            items[i] = new Item();
            st.nextToken();
            items[i].weight = (int)st.nval;
            st.nextToken();
            items[i].value = (int)st.nval;
        }
        st.nextToken();
        int W = (int)st.nval;
        int[] dp = new int[W + 1];
        boolean[][] selected = new boolean[n][W + 1];
        for(int i = 0; i < n; ++i) {
            int w = items[i].weight;
    	    int v = items[i].value;
    	    for(int j = W; j >= w; --j) {
    	        if(dp[j] < dp[j - w] + v) {
    	            dp[j] = dp[j - w] + v;
    	            selected[i][j] = true;
    	        }
    	    }
        }
        StringBuilder output = new StringBuilder("Maximum value in 0/1 Knapsack: ").append(dp[W]).append('\n');
        output.append("Items selected:\n");
        int currentW = W;
        for(int i = n - 1; i >= 0; --i) {
    	    if(selected[i][currentW]) {
    	        output.append("Item ").append(i + 1).append(": Weight = ").append(items[i].weight).append(", Value = ").append(items[i].value).append('\n');
    	        currentW -= items[i].weight;
    	    }
    	}
    	System.out.print(output);
	}
}

class Item {
    int weight, value;
}
