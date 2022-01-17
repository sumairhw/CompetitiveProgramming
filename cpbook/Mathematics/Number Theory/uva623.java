import java.util.*;
import java.math.*;

public class uva623 {
	public static void main(String [] args) {
		Scanner read = new Scanner(System.in);
		while (read.hasNextLine()) {
			int num = read.nextInt();
			if (num == 0) break;
			BigInteger fact = BigInteger.ONE;
			for (int i = 2; i <= num ; i++ ) {
				fact = fact.multiply(BigInteger.valueOf(i));
			}
			System.out.println(num + "!");
			System.out.println(fact);
		}
	}
}