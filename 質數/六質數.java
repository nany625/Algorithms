import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        int n;
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0)
            output.append(n).append(sexyPrime(n) ? " is prime\n" : " is not prime\n");
        System.out.print(output);
	}
	
	static boolean sexyPrime(int n) {
        if(n <= 3)
            return n > 1;
        if(n % 2 == 0 || n % 3 == 0)
            return false;
        int limit = (int)Math.sqrt(n);
        for(int i = 5; i <= limit; i += 6) {
            if(n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }
}
