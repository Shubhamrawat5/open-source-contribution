package com.company;


public class largestSubArray {
    public static void main(String[] args) {
        int[] a =  {-2, -3, 4, -1, -2, 1, 5, -3};
        System.out.println(maxSubArraySum(a));
//        System.out.println(maxSubArraySum(a,a.length));
    }


    static int maxSubArraySum(int[] a){
        int size = a.length;
        int max = Integer.MIN_VALUE, maxEnding = 0;

        for (int j : a) {
            maxEnding += j;
            if (max < maxEnding) {
                max = maxEnding;
            }
            if (maxEnding < 0) {
                maxEnding = 0;
            }

        }
        return max;
    }


// another approch
//        static int maxSubArraySum(int[] a, int size)
//        {
//            int max_so_far = a[0];
//            int curr_max = a[0];
//
//            for (int i = 1; i < size; i++)
//            {
//                curr_max = Math.max(a[i], curr_max+a[i]);
//                max_so_far = Math.max(max_so_far, curr_max);
//            }
//            return max_so_far;
//        }



    }




