import java.io.*;
import java.math.*;

public class Main {
    static BigInteger[][] temp = new BigInteger[2][2];
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int n = (int)st.nval;
            if(n <= 1) {
                output.append("The Fibonacci number for ").append(n).append(" is ").append(n).append('\n');
                continue;
            }
            output.append("The Fibonacci number for ").append(n).append(" is ").append(powerMatrix(new BigInteger[][]{{BigInteger.ONE, BigInteger.ONE}, {BigInteger.ONE, BigInteger.ZERO}}, n - 1)).append('\n');
        }
        System.out.print(output);
	}
	
	static void multiplyMatrix(BigInteger[][] a, BigInteger[][] b) {
	    temp[0][0] = a[0][0].multiply(b[0][0]).add(a[0][1].multiply(b[1][0]));
	    temp[0][1] = a[0][0].multiply(b[0][1]).add(a[0][1].multiply(b[1][1]));
	    temp[1][0] = a[1][0].multiply(b[0][0]).add(a[1][1].multiply(b[1][0]));
	    temp[1][1] = a[1][0].multiply(b[0][1]).add(a[1][1].multiply(b[1][1]));
	    a[0][0] = temp[0][0];
	    a[0][1] = temp[0][1];
	    a[1][0] = temp[1][0];
	    a[1][1] = temp[1][1];
	}
	
	static BigInteger powerMatrix(BigInteger[][] matrix, int n) {
	    BigInteger[][] result = {{BigInteger.ONE, BigInteger.ZERO}, {BigInteger.ZERO, BigInteger.ONE}};
	    while(n > 0) {
	        if((n & 1) == 1)
	            multiplyMatrix(result, matrix);
	        multiplyMatrix(matrix, matrix);
	        n >>= 1;
	    }
	    return result[0][0];
	}
}
