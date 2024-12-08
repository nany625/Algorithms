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
        System.out.println("Length of LIS of " + array.toString() + " is " + lengthOfLIS(array));
	}
	
	static int binarySearch(ArrayList<Integer> array, int key) {
        int left = 0, right = array.size() - 1;
        while(left <= right) {
            int mid = left + (right - left >> 1);
            if(array.get(mid) < key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
    
    static int lengthOfLIS(ArrayList<Integer> array) {
        ArrayList<Integer> LIS = new ArrayList<>();
        int length = 0;
        for(Integer i : array) {
            int pos = binarySearch(LIS, i);
            if(pos == LIS.size())
                LIS.add(i);
            else
                LIS.set(pos, i);
        }
        return LIS.size();
    }
}
