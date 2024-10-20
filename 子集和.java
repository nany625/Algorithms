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
        st.nextToken();
        int sum = (int)st.nval;
        System.out.println(sum + " is " + (isSubsetSum(array, array.size(), sum) ? "" : "not ") + "subsetsum of " + array.toString());
	}
	
	static boolean isSubsetSum(ArrayList<Integer> array, int arraySize, int sum) {
        boolean[] subsetSum = new boolean[sum + 1];
        subsetSum[0] = true;
        for(int i = 0; i < arraySize && !subsetSum[sum]; ++i) {
            for(int j = sum; j >= array.get(i) && !subsetSum[sum]; --j)
                subsetSum[j] |= subsetSum[j - array.get(i)];
        }
        return subsetSum[sum];
    }
}
