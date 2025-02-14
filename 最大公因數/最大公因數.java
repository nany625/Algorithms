import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            long a = (long)st.nval;
            st.nextToken();
            long b = (long)st.nval;
            if(a == 0 && b == 0)
                break;
            output.append("GCD of ").append(a).append(" and ").append(b).append(": ").append(GCD(a, b)).append('\n');
        }
        System.out.print(output);
	}
	
	static long GCD(long a, long b) {
        return b == 0 ? a : GCD(b, a % b);
    }
}
