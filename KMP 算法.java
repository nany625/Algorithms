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
	
	static void computeLPSArray(String pattern, int len, int[] LPS) {
        int i = 1, length = 0;
        while(i < len) {
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
        int textLen = text.length(), patternLen = pattern.length();
        int[] LPS = new int[patternLen];
        computeLPSArray(pattern, patternLen, LPS);
        int i = 0, j = 0;
        while(i < textLen) {
            if(pattern.charAt(j) == text.charAt(i)) {
                ++i;
                ++j;
            }
            if(j == patternLen) {
                output.append("Pattern found at index ").append(i - j).append(".\n");
                j = LPS[j - 1];
            } else if(i < textLen && pattern.charAt(j) != text.charAt(i)) {
                if(j != 0)
                    j = LPS[j - 1];
                else
                    ++i;
            }
        }
    }
}
