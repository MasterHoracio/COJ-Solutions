import java.util.Scanner;
import java.util.Arrays;
import java.lang.Math;

public class Main {

	static final int MAX = 1000005;
	static final int MOD = 1000000;

	static int [] computeSolution(){
		int memo[] = new int [MAX];
		int aux;
		memo[0] = 1;
		for(int i = 1; i <= 1000000; i++){
			aux = i;
			memo[i] = (memo[(int)(aux - Math.sqrt(aux))]%MOD + memo[(int)(Math.log(aux))]%MOD + memo[ (int)(aux * Math.sin(aux) * Math.sin(aux)) ]%MOD)%MOD;
		}
		return memo;
	}

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int dp[] = new int[MAX];
		int n;

		dp = computeSolution();

		while(sc.hasNextInt()){
			n = sc.nextInt();
			if(n == -1)
				break;
			System.out.println(dp[n]);
		}

	}

}