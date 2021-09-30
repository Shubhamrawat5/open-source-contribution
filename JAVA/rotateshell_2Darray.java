import java.io.*;
import java.util.*;

public class Main {

  public static void main(String[] args) throws Exception {

    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();
    
    int[][] a= new int[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            a[i][j]=sc.nextInt();
        }
    }
    
    int s= sc.nextInt();
    int r= sc.nextInt();
    
    rotateShell(a,s,r);
    display(a);
  }
  
  public static void rotateShell(int[][] a, int s, int r){
      int[] oned= get1D(a,s);
      rotate(oned,r);
      fillShell(a,s,oned);
  } 
  
  
  public static void rotate(int[] a,int r){
      
      r=r%a.length;
      if(r<0){
          r+=a.length;
      }
      
      reverse(a,0,a.length-r-1);
      reverse(a,a.length-r,a.length-1);
      reverse(a,0,a.length-1);
      
  }
  
  public static void reverse(int[] a,int li,int ri){
      
      while(li<ri){
          int temp=a[li];
          a[li]=a[ri];
          a[ri]=temp;
          
          
          li++;
          ri--;
          
      }
  }
  
  public static int[] get1D(int[][] a,int s){
      int minr=s-1;
      int minc=s-1;
      
      int maxr=a.length-s;
      int maxc=a[0].length-s;
      
      int size=2*(maxr-minr+maxc-minc);
      
      int[] oneD= new int[size];
      int idx=0;
      
      for(int i=minr,j=minc;i<=maxr;i++){
          oneD[idx]=a[i][j];
          idx++;
      }
      for(int i=maxr,j=minc+1;j<=maxc;j++){
          oneD[idx]=a[i][j];
          idx++;
      }
      for(int i=maxr-1,j=maxc;i>=minr;i--){
          oneD[idx]=a[i][j];
          idx++;
      }
      for(int i=minr,j=maxc-1;j>=minc+1;j--){
      oneD[idx]=a[i][j];
          idx++;
      }
      
      return oneD;
  }
  
  
  public static void fillShell(int[][] a,int s,int[] oneD){
      
       int minr=s-1;
      int minc=s-1;
      
      int maxr=a.length-s;
      int maxc=a[0].length-s;
      
      
      int idx=0;
      
      for(int i=minr,j=minc;i<=maxr;i++){
          a[i][j]=oneD[idx];
          idx++;
      }
      for(int i=maxr,j=minc+1;j<=maxc;j++){
          a[i][j]=oneD[idx];
          idx++;
      }
      for(int i=maxr-1,j=maxc;i>=minr;i--){
          a[i][j]=oneD[idx];
          idx++;
      }
      for(int i=minr,j=maxc-1;j>=minc+1;j--){
          a[i][j]=oneD[idx];
          idx++;
      }
      
  }

  public static void display(int[][] arr) {
    for (int i = 0; i < arr.length; i++) {
      for (int j = 0; j < arr[0].length; j++) {
        System.out.print(arr[i][j] + " ");
      }
      System.out.println();
    }
  }

}
