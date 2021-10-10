/*
* This C++ program can multiply any two square or rectangular matrices.
* The below program multiplies two square matrices of size 4 * 4.
* There is also an example of a rectangular matrix for the same code (commented below).
* We can change the Matrix value with the number of rows and columns (from MACROs) for Matrix-1
* and Matrix-2 for different dimensions.
*/

/*
* Note: i- The number of columns in Matrix-1 must be equal to the number of rows in Matrix-2.
*	 ii- Output of multiplicationof Matrix-1 and Matrix-2, results with equalto the number
*		 of rows of Matrix-1 and thenumber of columns of Matrix-2 i.e. rslt[R1][C2].
*/

#include <iostream>

using namespace std;

// Edit MACROs here, according to your Matrix Dimensions for mat1[R1][C1] and mat2[R2][C2]
#define R1 4		 // number of rows in Matrix-1
#define C1 4		 // number of columns in Matrix-1
#define R2 4		 // number of rows in Matrix-2
#define C2 4		 // number of columns in Matrix-2

void mulMat(int mat1[][C1], int mat2[][C2]) {
	int rslt[R1][C2];

	cout << "Multiplication of given two matrices is:\n" << endl;

	for (int i = 0; i < R1; i++) {
		for (int j = 0; j < C2; j++) {
			rslt[i][j] = 0;

			for (int k = 0; k < R2; k++) {
				rslt[i][j] += mat1[i][k] * mat2[k][j];
			}

			cout << rslt[i][j] << "\t";
		}

		cout << endl;
	}
}

int main(void) {
	// Square Matrices
	// R1 = 4, C1 = 4 and R2 = 4, C2 = 4 (Update these values in MACROs)
	int mat1[R1][C1] = {
			{1, 1, 1, 1},
			{2, 2, 2, 2},
			{3, 3, 3, 3},
			{4, 4, 4, 4}
	};

	int mat2[R2][C2] = {
			{1, 1, 1, 1},
			{2, 2, 2, 2},
			{3, 3, 3, 3},
			{4, 4, 4, 4}
	};

	/*
	// Rectangular Matrices
	// R1 = 3, C1 = 4 and R2 = 4, C2 = 3 (Update these values in MACROs)
	int mat1[R1][C1] = {
				{1, 1, 1, 1},
				{2, 2, 2, 2},
				{3, 3, 3, 3}
	};

	int mat2[R2][C2] = {
				{1, 1, 1},
				{2, 2, 2},
				{3, 3, 3},
				{4, 4, 4}
	};
	*/

	if (C1 != R2) {
		cout << "The number of columns in Matrix-1 must be equal to the number of rows in "
				"Matrix-2" << endl;
		cout << "Please update MACROs according to your array dimension in #define section"
				<< endl;

		exit(EXIT_FAILURE);
	}

	mulMat(mat1, mat2);

	return 0;
}

// This code is contributed by Manish Kumar (mkumar2789)
