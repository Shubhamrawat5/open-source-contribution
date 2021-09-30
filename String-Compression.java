import java.io.*;
import java.util.*;

public class Main {

	public static String compression1(String str){
	    
	    String str1="";
	    str1+=str.charAt(0);
	    
	    for(int i=0;i<str.length();i++){
	        if(str.charAt(i)==str1.charAt(str1.length()-1)){
	            continue;
	        }
	        else{
	            str1+=str.charAt(i);
	        }
	    }

		return str1;
	}

	public static String compression2(String str){
	    
	    String str2="";
	    str2+=str.charAt(0);
	    
	    int c=1;
	    for(int i=1;i<str.length();i++){
	        if(str.charAt(i)==str2.charAt(str2.length()-1)){
	            c++;
	        }
	        else{
	            if(c>1){
	                str2+=c;
	            }
	            str2+=str.charAt(i);
	            c=1;
	        }
	    }
	   
	    if(c>1){
	        str2+=c;
	    }

		return str2;
	}
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String str = scn.next();
		System.out.println(compression1(str));
		System.out.println(compression2(str));
	}

}
