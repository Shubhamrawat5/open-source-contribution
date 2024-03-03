package com.company;

//Question : print series : 1,1,2,3,4,9,8,27,16,81,32...
public class TCSSeriesQuestion {
    public static void main(String[] args) {
        int a = 1, b=1;
        for (int i=0;i<15;i++){
            if (i==1||i==0){
                a=1;b=1;
                System.out.print("1, ");
            }else if (i%2==0){
                a*=2;
                System.out.print(a+", ");
            }else if (i%2==1){
                b*=3;
                System.out.print(b+", ");
            }
        }
    }

}
