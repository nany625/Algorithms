import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 1000000, primeCount;
    static boolean[] isComposite = new boolean[MAX_NUM + 1];
	static ArrayList<Integer> primes = new ArrayList<>();
	public static void main(String[] args) throws IOException {
	    primeTrailDivision();
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        int n;
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0)
            output.append(n).append(" is ").append(isPrime(n) ? "prime\n" : "not prime\n");
        System.out.print(output);
	}
	
	static boolean isPrime(int n) {
        int limit = (int)Math.sqrt(n);
        for(int i = 0; i < primeCount && primes.get(i) <= limit; ++i) {
            if(n % primes.get(i) == 0)
                return false;
        }
        return true;
    }
    
    static void primeTrailDivision() {
        primes.add(2);
        primeCount = 1;
        for(int n = 3; n <= MAX_NUM; n += 2) {
            if(isPrime(n)) {
                primes.add(n);
                ++primeCount;
            }
        }
    }
}
