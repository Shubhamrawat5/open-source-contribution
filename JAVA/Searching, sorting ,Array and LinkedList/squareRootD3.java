package com.company;

public class squareRootD3 {
    public static void main(String[] args) {
        int n = 14;
//    meth 1
        System.out.println(Math.sqrt(n));

//        meth2
        int i=1, result = 0;
        while (i*i<=n){
            result=i;
            i++;
        }
        System.out.println(result); //it will return floor value of square root
        
        
        
        
        
        
        
        
        
    }








}
