import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 1000000;
    static int[] mark = new int[(MAX_NUM >> 6) + 1];
	static ArrayList<Integer> primes = new ArrayList<>();
	public static void main(String[] args) throws IOException {
	    eulerSieve();
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        int n;
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0)
            output.append(n).append(n == 2 || ((n & 1) == 1 && !GET(n >> 1)) ? " is prime\n" : " is not prime\n");
        System.out.print(output);
	}
	
	static boolean GET(int n) {
	    return (mark[n >> 5] & (1 << (n & 31))) != 0;
	}
	
	static void SET(int n) {
	    mark[n >> 5] |= 1 << (n & 31);
	}
	
	static void eulerSieve() {
	    SET(0);
	    primes.add(2);
        for(int n = 3; n <= MAX_NUM; n += 2) {
            if(!GET(n >> 1))
                primes.add(n);
            for(int i = 1, temp; (temp = primes.get(i) * n) <= MAX_NUM; ++i) {
                SET(temp >> 1);
                if(n % primes.get(i) == 0)
                    break;
            }
        }
    }
}
