package com.company;

public class SearchInInfiniteSortedArrayD3 {
    public static void main(String[] args) {
        int[] arr = {10,20,30,40, 90, 100, 130, 140, 160, 170};
        int n= 40;
        int res = SearchElement(arr,n );
        if (res == -1) {
            System.out.println("Not Found");
        } else {
            System.out.println("element found at index : "+res);
        }
    }
//neive solution
    public static int SearchElement(int[] arr, int n){
        int i=0;
        while (arr[i]<=n){
            if (arr[i]==n){
//                System.out.println("element found at index : "+ i);
                return i;
            }
            i++;

        }
        return -1;



    }
}
