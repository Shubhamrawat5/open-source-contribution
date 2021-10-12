package com.company;

public class PrefixSumTechniqueD2 {
    public static void main(String[] args) {
        int[] arr = {2,8,3,9,6,5,4};
        int[] prefixArr = new int[arr.length];
        prefixArr[0]=arr[0];
        for (int i = 1; i < arr.length; i++) {
            prefixArr[i] = arr[i]+ prefixArr[i-1];
        }

        System.out.println(sumOfPrefix(2,4,prefixArr));
    }

    public static int sumOfPrefix(int i,int j ,int[] a){
/*
        for (Integer x: a) {
            System.out.print(x+ " ");
        }
*/
        if (i != 0) {
            return a[j]-a[i-1];
        } else {
            return a[j];
        }
    }
}
