import java.util.*;
import java.math.*;

public class Keen{
	
	public static void main(String args[]){

		Scanner in = new Scanner(System.in);
        String[] factorial = new String[41];
        String past = "1";
		int TC, num;

		BigInteger fact;
		
		for(int i = 2; i <= 40; i++){
		    fact = BigInteger.valueOf(i);
		    factorial[i] = fact.multiply(new BigInteger(past)).toString();
		    past = factorial[i];
		}

		TC = in.nextInt();
		
        while(TC-- > 0){
            num = in.nextInt();
            System.out.println(factorial[num]);
        }

	}
}