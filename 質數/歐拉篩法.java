import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 1000000;
    static boolean[] isComposite = new boolean[MAX_NUM + 1];
	static ArrayList<Integer> primes = new ArrayList<>();
	public static void main(String[] args) throws IOException {
	    eulerSieve();
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        int n;
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0)
            output.append(n).append(!isComposite[n] ? " is prime\n" : " is not prime\n");
        System.out.print(output);
	}
	
	static void eulerSieve() {
	    isComposite[0] = isComposite[1] = true;
        for(int n = 2; n <= MAX_NUM; ++n) {
            if(!isComposite[n])
                primes.add(n);
            for(int i = 0, temp; i < primes.size() && (temp = primes.get(i) * n) <= MAX_NUM; ++i) {
                isComposite[temp] = true;
                if(n % primes.get(i) == 0)
                    break;
            }
        }
    }
}
