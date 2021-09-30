//This code has time complexity of O(n*n) because of 2 loops.
import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) throws Exception {
      
      
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      
      int[][] a=new int[n][n];
      
      for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
              a[i][j]=sc.nextInt();
          }
      }
      
      
     for(int k=0;k<n;k++){
          for(int i=0,j=d;j<n;i++,j++){
              System.out.println(a[i][j]);
          }
     }
      

  }

}


// Below code has time complexity of O(n*n*n) because extra space and extra loop


for(int g=0;g<n;g++){
          for(int i=0;i<n;i++){
              for(int j=0;j<n;j++){
              if(g==j-i){
                  System.out.println(a[i][j]);
              }
              }
          }
