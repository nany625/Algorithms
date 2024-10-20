import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        ArrayList<Integer> array = new ArrayList<>();
        int n;
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0)
            array.add(n);
        System.out.println("Max subarray sum of " + array.toString() + ": " + maxSubArraySum(array, array.size()));
	}
	
	static int maxSubArraySum(ArrayList<Integer> array, int arraySize) {
        int max = array.get(0), curr = array.get(0);
        for(int i = 1; i < arraySize; ++i) {
            curr = Math.max(array.get(i), curr + array.get(i));
            max = Math.max(max, curr);
        }
        return max;
    }
}
