import java.io.*;
import java.util.*;

public class Main {

	public static String toggleCase(String str){
	    
	    StringBuilder sb = new StringBuilder();
	    
	    for(int i=0;i<str.length();i++){
	        char ch = str.charAt(i);
	    
	    if(ch>=65&&ch<=90){
	        sb.append((char)(ch+32));
	    }
	    else{
	        sb.append((char)(ch-32));
	    }
	    
	    }

		return sb.toString();
	}
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String str = scn.next();
		System.out.println(toggleCase(str));
	}

}
