/* 
------------------------------------------------------------------------------------------------

DESCRIPTION: THIS IS A PROGRAM TO FIND THE DETERMINANT OF A MATRIX

------------------------------------------------------------------------------------------------
*/

import java.util.Scanner;

public class DeterminantOfMatrix {
	private static Scanner inp;
	
	public static void main(String[] args) {
		int[][] arr = new int[2][2];
		
		int i, j, determinant = 0;
		
		inp= new Scanner(System.in);
		
		System.out.println("\n Please Enter the Matrix Items :  ");
		for(i = 0; i < 2; i++) {
			for(j = 0; j < 2; j++) {
				arr[i][j] = sc.nextInt();
			}		
		}
		
		determinant = (arr[0][0] * arr[1][1]) - (arr[0][1] * arr[1][0]);

		System.out.println("The Determinant of 2 * 2 Matrix = " + determinant );
		
	}
}
