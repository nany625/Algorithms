import java.io.*;

public class Main {
    static int MAX_NUM = 1000000;
    static int[] mark = new int[(MAX_NUM >> 5) + 1];
	public static void main(String[] args) throws IOException {
	    eratosthenesSieve();
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        int n;
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0)
            output.append(n).append(!GET(n) ? " is prime\n" : " is not prime\n");
        System.out.print(output);
	}

    static boolean GET(int n) {
	    return (mark[n >> 5] & (1 << (n & 31))) != 0;
	}
	
	static void SET(int n) {
	    mark[n >> 5] |= 1 << (n & 31);
	}
    
	static void eratosthenesSieve() {
	    SET(0);
        SET(1);
        int limit = (int)Math.sqrt(MAX_NUM);
        for(int n = 2; n <= MAX_NUM; ++n) {
            if(n <= limit && !GET(n)) {
                for(int i = n * n; i <= MAX_NUM; i += n)
                    SET(i);
            }
        }
    }
}
