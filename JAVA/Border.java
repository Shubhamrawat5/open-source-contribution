
import java.util.Scanner;
class SumOfBorderElements_2D
{
    int m,n;
    int A[][];
    int s;
    SumOfBorderElements_2D(int m1,int n1){
        m=m1;
        n=n1;
        A=new int[m][n];
    }
    Scanner sc=new Scanner(System.in);
    void input(){
        System.out.println("Enter Elements");
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++){
                A[i][j]=sc.nextInt();
            }
        }
        System.out.println("Original Matrix");
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                System.out.println(A[i][j]+"\t");
            }
        }
    }
    void sum(){
        s=0;
        for(int i=0;i<m;i++)
        s+=A[0][i];
        for(int j=1;j<n;j++)
        s+=A[n-1][j];
        for(int i=0;i<n-1;i++)
        s+=A[m-1][i];
        for(int j=1;j<n-1;j++)
        s+=A[j][0];
        System.out.println("SUM OF BORDER ELEMENTS (INSORTED)"+s);
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter Column");
        int m1=sc.nextInt();
        System.out.println("Enter Row");
        int n1=sc.nextInt();
        SumOfBorderElements_2D obj=new SumOfBorderElements_2D(m1, n1);
        obj.input();
        obj.sum();
    }
}