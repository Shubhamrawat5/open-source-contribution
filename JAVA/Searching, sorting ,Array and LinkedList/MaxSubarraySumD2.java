package com.company.Day;

public class MaxSubarraySumD2 {
    public static void main(String[] args) {
        int[] arr = {2,3,-8,7,-1,2,3};
        System.out.println(maxSumArr(arr));
    }

    public static int maxSumArr(int[] arr) {
        int res = arr[0];
        int n = arr.length;

        for (int i = 0; i < n; i++) {
            int curr = 0;
            for (int j = i; j < n; j++) {
                curr+=arr[j];
                res = Math.max(curr,res);
            }
        }
        return res;
    }
}
