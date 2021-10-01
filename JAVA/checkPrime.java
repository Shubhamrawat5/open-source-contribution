import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.lang.reflect.*;

	

public class checkPrime {

    static boolean isPrime(int n) {
		if (n <= 1) {
			return false;
		}
		if (n == 2) {
			return true;
		} else if (n % 2 == 0) {
			return false;
		}
		for (int i = 3; i <= Math.sqrt(n); i += 2) {
			if (n % i == 0) {

				return false;

			}
		}
		return true;
	}
    
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int number = Integer.parseInt(br.readLine());

		if (isPrime(number))
			System.out.println(number + " is a prime number");
		else
			System.out.println(number + " is not a prime number");

	}

}
