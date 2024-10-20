import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		ArrayList<Integer> array = new ArrayList<>();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER)
            array.add((int)st.nval);
        int[] reg = new int[array.size()];
        long[] swap = new long[1];
        MergeSort(array, reg, 0, array.size() - 1, swap);
        System.out.println("Number of inversions: " + swap[0]);
	}
	
	static void MergeSort(ArrayList<Integer> array, int[] reg, int left, int right, long[] swap) {
        if(left < right) {
            int mid = left + ((right - left) >> 1);
            MergeSort(array, reg, left, mid, swap);
            MergeSort(array, reg, mid + 1, right, swap);
            int leftPointer = left, rightPointer = mid + 1;
            for(int i = left; i <= right; ++i) {
                if(leftPointer > mid) {
                    reg[i] = array.get(rightPointer++);
                    swap[0] += mid - leftPointer + 1;
                } else if(rightPointer > right)
                    reg[i] = array.get(leftPointer++);
                else if(array.get(leftPointer) <= array.get(rightPointer))
                    reg[i] = array.get(leftPointer++);
                else {
                    reg[i] = array.get(rightPointer++);
                    swap[0] += mid - leftPointer + 1;
                }
            }
            for(int i = left; i <= right; ++i)
                array.set(i, reg[i]);
        }
    }
}
