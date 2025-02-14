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

/*
Input:
4
2 3
3 4
4 5
5 6
8

Output:
Maximum value in 0/1 Knapsack: 10
Items selected:
Item 4: Weight = 5, Value = 6
Item 2: Weight = 3, Value = 4
*/

/*
dp:
   | 0  1  2  3  4  5  6  7  8
---+--------------------------
 0 | 0  0  3  3  3  3  3  3  3
 1 | 0  0  3  4  4  7  7  7  7
 2 | 0  0  3  4  5  7  8  9  9
 3 | 0  0  3  4  5  7  8  9 10

selected:
   | 0  1  2  3  4  5  6  7  8
---+--------------------------
 0 | 0  0  1  1  1  1  1  1  1
 1 | 0  0  0  1  1  1  1  1  1
 2 | 0  0  0  0  1  0  1  1  1
 3 | 0  0  0  0  0  0  0  0  1
*/
