
//https://practice.geeksforgeeks.org/problems/element-appearing-once2552/1

import java.io.*;
import java.util.*;
class findElementAppearsOncea
{
    public static void main (String[] args)
    {
        
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int n = sc.nextInt();
            int[] arr = new int[n];
            
            for (int i = 0; i < n; ++i)
                arr[i] = sc.nextInt ();

    		System.out.println (new Sol().search (arr, n));
        }
        
    }
}

class Sol
{
    public static int search(int ar[], int N)
    {
        // your code here
        int res = ar[0];
        for (int i = 1; i < N; i++)
            res = res ^ ar[i];
    
        return res;
    }
}