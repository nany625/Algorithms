import java.io.*;

public class Main {
    static int MAX_NUM = 1000000;
    static boolean[] isComposite = new boolean[MAX_NUM + 1];
	public static void main(String[] args) throws IOException {
	    eratosthenesSieve();
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        int n;
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0)
            output.append(n).append(!isComposite[n] ? " is prime\n" : " is not prime\n");
        System.out.print(output);
	}
	
	static void eratosthenesSieve() {
	    isComposite[0] = isComposite[1] = true;
        int limit = (int)Math.sqrt(MAX_NUM);
        for(int n = 2; n <= MAX_NUM; ++n) {
            if(n <= limit && !isComposite[n]) {
                for(int i = n * n; i <= MAX_NUM; i += n)
                    isComposite[i] = true;
            }
        }
    }
}
