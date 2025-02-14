import java.io.*;

public class Main {
    static StringBuilder output = new StringBuilder();
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        while(st.nextToken() == StreamTokenizer.TT_WORD) {
            String text = st.sval;
            st.nextToken();
            String pattern = st.sval;
            KMPSearch(text, pattern);
        }
    	System.out.print(output);
	}
	
	static void computeLPSArray(String pattern, int[] LPS) {
        int i = 1, length = 0;
        while(i < pattern.length()) {
            if(pattern.charAt(i) == pattern.charAt(length))
                LPS[i++] = ++length;
            else {
                if(length != 0)
                    length = LPS[length - 1];
                else
                    LPS[i++] = 0;
            }
        }
    }
    
    static void KMPSearch(String text, String pattern) {
        int[] LPS = new int[pattern.length()];
        computeLPSArray(pattern, LPS);
        int i = 0, j = 0;
        while(i < text.length()) {
            if(pattern.charAt(j) == text.charAt(i)) {
                ++i;
                ++j;
            }
            if(j == pattern.length()) {
                output.append("Pattern found at index ").append(i - j).append(".\n");
                j = LPS[j - 1];
            } else if(i < text.length() && pattern.charAt(j) != text.charAt(i)) {
                if(j != 0)
                    j = LPS[j - 1];
                else
                    ++i;
            }
        }
    }
}
