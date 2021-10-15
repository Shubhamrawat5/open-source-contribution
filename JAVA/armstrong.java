import java.io.*;

public class armstrong
{
	public static void main(String []arg) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,r,sum=0,temp;
		System.out.println("Give The Value:");
		n=Integer.parseInt(br.readLine());
		temp=n;    
		while(n>0)    
		{    
		r=n%10;    
		sum=sum+(r*r*r);    
		n=n/10;    
		}    
		if(temp==sum)    
		System.out.println("armstrong  number ");    
		else    
		System.out.println("not armstrong number"); 
	}
}