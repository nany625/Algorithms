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
        long n;
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (long)st.nval) != 0)
            output.append("Sum of true factors of ").append(n).append(": ").append(trueFactorSum(n)).append('\n');
        System.out.print(output);
	}

    static boolean GET(int n) {
	    return (mark[n >> 5] & (1 << (n & 31))) != 0;
	}
	
	static void SET(int n) {
	    mark[n >> 5] |= 1 << (n & 31);
	}
    
	static void eulerSieve() {
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
    
    static long trueFactorSum(long n) {
        long sum = 1, limit = (long)Math.sqrt(n), temp = n;
        for(int i = 0; i < primes.size() && primes.get(i) <= limit; ++i) {
            if(n % primes.get(i) == 0) {
                long tempSum = 1, term = 1;
                do {
                    tempSum += term *= primes.get(i);
                    n /= primes.get(i);
                } while(n % primes.get(i) == 0);
                sum *= tempSum;
                limit = (long)Math.sqrt(n);
            }
        }
        if(n > 1)
            sum *= (1 + n);
        return sum - temp;
    }
}
