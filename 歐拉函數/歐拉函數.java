import java.io.*;
import java.util.*;

public class main {
    static int MAX_NUM = 1000000;
    static boolean[] isComposite = new boolean[(MAX_NUM >> 1) + 1];
	static ArrayList<Integer> primes = new ArrayList<>();
	public static void main(String[] args) throws IOException {
	    eulerSieve();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		long n;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (long)st.nval) != 0)
			output.append("φ(").append(n).append(") = ").append(n == 1 ? 0 : eulerTotient(n)).append('\n');    // 小於等於正整數n的所有與n互質的正整數個數
		System.out.print(output);
	}
	
	static void eulerSieve() {
	    primes.add(2);
        for(int n = 3; n <= MAX_NUM; n += 2) {
            if(!isComposite[n >> 1])
                primes.add(n);
            for(int i = 1, temp; i < primes.size() && (temp = primes.get(i) * n) <= MAX_NUM; ++i) {
                isComposite[temp >> 1] = true;
                if(n % primes.get(i) == 0)
                    break;
            }
        }
    }
    
    static long eulerTotient(long n) {
        long ans = n, limit = (long)Math.sqrt(n);
        for(int i = 0; i < primes.size() && primes.get(i) <= limit; ++i) {
            if(n % primes.get(i) == 0) {
                ans -= ans / primes.get(i);
                do {
                    n /= primes.get(i);
                } while(n % primes.get(i) == 0);
                limit = (long)Math.sqrt(n);
            }
        }
        if(n > 1)
            ans -= ans / n;
        return ans;
    }
}
