import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 1000000, primeCount;
    static boolean[] isComposite = new boolean[MAX_NUM + 1];
	static ArrayList<Integer> primes = new ArrayList<>();
	public static void main(String[] args) throws IOException {
        sieve();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        long n;
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (long)st.nval) != 0)
            output.append("Sum of true factors of ").append(n).append(": ").append(trueFactorSum(n)).append('\n');
        System.out.print(output);
	}
	
	static void sieve() {
	    isComposite[0] = isComposite[1] = true;
        int limit = (int)Math.sqrt(MAX_NUM);
        for(int n = 2; n <= MAX_NUM; ++n) {
            if(!isComposite[n]) {
                primes.add(n);
                ++primeCount;
                if(n <= limit) {
                    for(int i = n * n; i <= MAX_NUM; i += n)
                        isComposite[i] = true;
                }
            }
        }
    }
    
    static long trueFactorSum(long n) {
        long sum = 1, limit = (long)Math.sqrt(n), temp = n;
        for(int i = 0; i < primeCount && primes.get(i) <= limit; ++i) {
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
