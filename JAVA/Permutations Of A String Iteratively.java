import java.io.*;
import java.util.*;

public class Main {

	public static void solution(String str){
	    
	    int n= str.length();
	    int tnp = fact(n);
	    
	    for(int i=0;i<tnp;i++){
	        StringBuilder sb = new StringBuilder(str);
	        int temp=i;
	        
	        for(int div=n;div>0;div--){
	            int q=temp/div;
	            int r=temp%div;
	            
	            System.out.print(sb.charAt(r));
	            sb.deleteCharAt(r);
	            
	            temp=q;
	            
	        }
	        
	        System.out.println();
	    }



	}
	
	public static int fact(int n){
	    int val=1;
	    for(int i=2;i<=n;i++){
	        val*=i;
	    }
	    return val;
	}
	
	
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String str = scn.next();
		solution(str);
	}

}
