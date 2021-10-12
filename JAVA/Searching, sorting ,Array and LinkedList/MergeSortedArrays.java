package com.company;

public class MergeSortedArrays {
    public static void main(String[] args) {
        int[] arr1 = {1, 3, 4, 6};
        int[] arr2 = {2, 5, 7, 8};

        mergeArray(arr1, arr2);

    }

    static void mergeArray(int[] arr1, int[] arr2) {
        int m = arr1.length;
        int n = arr2.length;
        int[] sortedArray = new int[m + n];
        int i = 0, j = 0, k = 0;

        while (i < m && j < n) {

            if (arr1[i] < arr2[j]) {
                sortedArray[k++] = arr1[i++];

            } else {
                sortedArray[k++] = arr2[j++];
            }


        }
        while (i < m) {
            sortedArray[k++] = arr1[i++];
        }

        while (j < n) {
            sortedArray[k++] = arr2[j++];
        }

        for (Integer x : sortedArray) {
            System.out.print(x + " ");
        }

    }
}

