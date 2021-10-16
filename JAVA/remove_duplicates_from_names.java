import java.util.*;
public class TestMain{
    public static void main(String[] args)
    {
        //implement the required business logic here
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number of Students:");
        int num=sc.nextInt();
        sc.nextLine();
        TreeSet<String> ts=new TreeSet<String>();
        for(int i=0;i<num;i++){
            ts.add(sc.nextLine());
        }
        Object[] str=ts.toArray();
        for(Object i:str){
            System.out.println(i);
        }
    }
}