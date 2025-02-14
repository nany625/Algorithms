import java.io.*;

public class Main {
    static int MAX_NUM = 10;
    static int[] parent = new int[MAX_NUM], rank = new int[MAX_NUM];
	public static void main(String[] args) throws IOException {
	    init();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
    		int x = (int)st.nval;
    		st.nextToken();
    		int y = (int)st.nval;
    		output.append(x).append(" is ").append(isConnected(x, y) ? "connected to " : "not connected to ").append(y).append('\n');
    		unite(x, y);
		}
		System.out.print(output);
	}

    static void init() {
        for(int n = 0; n < MAX_NUM; ++n)
            rank[parent[n] = n] = 0;
    }
    
    static int find(int x) {
        return parent[x] == x ? x : (parent[x] = find(parent[x]));
    }
    
    static void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX != rootY) {
            if(rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else if(rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else
                ++rank[parent[rootY] = rootX];
        }
    }
    
    static boolean isConnected(int x, int y) {
        return find(x) == find(y);
    }
}

/*
Input:
5 6
2 1
7 6
3 8
4 8
4 7
4 6
8 8
6 5
8 7

Output:
5 is not connected to 6
2 is not connected to 1
7 is not connected to 6
3 is not connected to 8
4 is not connected to 8
4 is not connected to 7
4 is connected to 6
8 is connected to 8
6 is connected to 5
8 is connected to 7
*/
