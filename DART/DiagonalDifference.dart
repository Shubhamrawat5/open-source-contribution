void main() {
  
  // The list denotes the elements of the matrix
  List<List<int>> matrix = [[1,3,2],[-3,-1,-3],[2,3,1]];
  
  print("Result : ${_calculateDiagonalDifference(matrix)}");
  
}
 
int _calculateDiagonalDifference(List<List<int>>matrix){
  
  /* Since the matrix is a square matrix */
  int n = matrix.length;
  /* leftSum is the sum of diagonal from left to right starting at martrix[0][0] */
  int leftSum = 0;
  
  /* rightSum is the sum of diagonal from right to left starting at matrix[0][2] */
  int rightSum = 0;
  
  /* tempAns is used to store the temporary answer so that it can be converted to a positive number if the sum is negative */
  int tempAns;
  
  
  for(int j = 0, k = n-1; j< n ; j++,k--){
    leftSum += matrix[j][j];
    rightSum += matrix[j][k];
  }
  
  tempAns = leftSum - rightSum;
  
  /* the following condition is to make the value of the difference positive */
  if(tempAns < 0){
    return tempAns + (tempAns * -2);
  }else{
    return tempAns;
  }  
}
