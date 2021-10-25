import java.io.IOException;
import java.util.Scanner;

public class Swastik
{
	public static void main(String[] args)throws IOException
	{
	    Scanner sc=new Scanner(System.in);
	    System.out.print("Enter a number greater than 2: ");
		int n=sc.nextInt();
		if(n<3)
		    System.out.println("Invalid Input");
	    else
	    {
    		for(int i=1;i<2*n;i++)
    		{
    		    for(int j=1;j<2*n;j++)
    		    {
    		        if(i==1 && j>n)
    		            System.out.print("*");
    		        else if((i<n)&&(j==1 || j==n))
    		            System.out.print("*");
    	            else if(i==n)
    	                System.out.print("*");
                    else if((i>n)&&(j==((2*n)-1) || j==n))
                        System.out.print("*");
                    else if(i==((2*n)-1)&& j<n)
                        System.out.print("*");
                    else
                        System.out.print(" ");
    		    }
    		    System.out.println("");
    		}
	    }
	    sc.close();
	}
}

