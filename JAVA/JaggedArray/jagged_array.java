// ***READ THE readme.md FILE FOR THE PROBLEM STATEMENT***

import java.util.*;

class jaggedarray{

public static void main(String args[]){
  Scanner sc=new Scanner(System.in);
  int n;
  int m;
 
  System.out.println("Enter no. of players");
  n=sc.nextInt();
 int[] [] arr=new int[n][]; // creating a two dimensional array
  double sum[]=new double[n]; 
 double avg[]=new double[n]; 
  for(int i=0;i<n;i++){
   sum[i]=0;
   avg[i]=0;
    System.out.println("Enter no. of matches played");
   m=sc.nextInt();
  arr[i]= new int[m]; // creating a jagged array
   for(int j=0;j<m;j++){
     System.out.println("Enter runs");
     arr[i][j]=sc.nextInt(); // taking input of the number of number of runs made in each match
     sum[i]+=arr[i][j];
}
avg[i]=sum[i]/m;
}
 for(int i=0;i<n;i++){
   System.out.println("Player     Sum       Average");
   System.out.println((i+1)+"   "+(sum[i])+"   "+(avg[i]));
}
}
}
