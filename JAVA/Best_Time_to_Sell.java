import java.util.Scanner;
class Best_Time_to_Sell 
{
public int maxprofit(int[] prices) 
{
    int ans=0, min = prices[0];
    for(int value : prices )
    {
        ans=Math.max(ans,value-min);
        min=Math.min(min , value);
    }
    return ans;
}
public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int[] prices= new int[7];
    System.out.println("Enter prices of 7 days :");
    for(int i=0;i<7;i++){
         prices[i]=sc.nextInt();
    }
    Best_Time_to_Sell obj = new Best_Time_to_Sell();
    int ans= obj.maxprofit(prices);
    System.out.println("profit :"+ans);
}
}