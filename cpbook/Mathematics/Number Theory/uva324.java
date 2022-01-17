import java.util.*;
import java.math.*;

public class uva324 {
	public static void main(String [] args) {
		Scanner read = new Scanner(System.in);
		while (true) {
			int num = read.nextInt();
			if (num == 0) break;
			BigInteger fact = BigInteger.ONE;
			for (int i = 2; i <= num ; i++) {
				fact = fact.multiply(BigInteger.valueOf(i));
			}
			String ans = String.valueOf(fact);
			int arr[] = new int[10];
			for (int i = 0; i < ans.length() ; i++ ) {
				int k = Integer.valueOf(ans.charAt(i) - '0');
				arr[k] = arr[k] + 1;
			}

			System.out.println(num + "! --"); System.out.print("   ");
			for (int i = 0; i < 10 ; i++ ) {
				if (i == 5) {System.out.println(); System.out.print("   ");}
				System.out.print("(" + i + ")");
				System.out.printf("%5d", arr[i]);
				if (i != 4 && i != 9) System.out.print("    ");
			}
			System.out.println();
		}
	}
}