import java.util.*;
import java.util.Scanner;

class Majority_Element{
    public int Majority(int[] nums)
    {
        int count =0;
        int majority_ele = nums[0];

        for(int i=0;i<nums.length;i++){
            if(count ==0){
                majority_ele = nums[i];
            }
            if(nums[i] == majority_ele){
                count ++;
            }
            else{
                count--;
            }
        }
        return majority_ele;
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the size of array elements: ");
        int size = sc.nextInt();

        int[] nums= new int[size];
        System.out.print("Enter the number of array elements : ");
        
        for(int i =0;i<size;i++){
            nums[i]=sc.nextInt();
        }
        Majority_Element obj = new Majority_Element();
        int majority_ele = obj.Majority(nums); 
        System.out.println("majority Element : "+majority_ele);
    }
}