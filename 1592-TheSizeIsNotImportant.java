import java.util.Scanner;
import java.math.BigInteger;

public class Main {

	public static void main(String[] agrs){
		Scanner sc = new Scanner(System.in);
		String num1, num2, ans;
		int TC;

		TC = sc.nextInt();

		while(TC-- > 0){

			num1 = sc.next();
			num2 = sc.next();

			BigInteger bg1 = new BigInteger(num1);
			BigInteger bg2 = new BigInteger(num2);

			bg1 = bg1.multiply(bg2);
			ans = bg1.toString();

			System.out.println(ans);

		}

	}

}