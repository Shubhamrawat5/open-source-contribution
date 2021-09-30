import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner s = new Scanner(System.in);
        int n=s.nextInt();
        int[][] a = new int[n][n];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                a[i][j]=s.nextInt();
            }
        }
        
        
        for(int i=0;i<n;i++){
            
            int min=a[i][0];
            int col=0;
            
            for(int j=0;j<n;j++){
                if(a[i][j]<min){
                    min=a[i][j];
                    col=j;
                }
            }
            
            
            
            boolean ans=true;
            
            for(int j=0;j<n;j++){
                
                if(a[j][col]>min){
                    ans=false;
                    break;
                }
            }
            
            if(ans==true){
                System.out.println(min);
                return;
            }
        }
        System.out.println("Invalid input");
        
    }

}
