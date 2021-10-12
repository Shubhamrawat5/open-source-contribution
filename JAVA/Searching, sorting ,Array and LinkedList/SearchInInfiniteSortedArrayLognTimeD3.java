package com.company;

public class SearchInInfiniteSortedArrayLognTimeD3 {

        static int binarySearch(int arr[], int l, int r, int x)
        {
            if (r>=l)
            {
                int mid = l + (r - l)/2;
                if (arr[mid] == x)
                    return mid;
                if (arr[mid] > x)
                    return binarySearch(arr, l, mid-1, x);
                return binarySearch(arr, mid+1, r, x);
            }
            return -1;
        }

        static int findPos(int arr[],int key)
        {
            int l = 0, h = 1;
            int val = arr[0];

            while (val < key)
            {
                l = h;
                if(2*h < arr.length-1)
                    h = 2*h;
                else
                    h = arr.length-1;

                val = arr[h];
            }

            return binarySearch(arr, l, h, key);
        }

        public static void main(String[] args)
        {
            int arr[] = new int[]{3, 5, 7, 9, 10, 90,
                    100, 130, 140, 160, 170};
            int ans = findPos(arr,165);

            if (ans==-1)
                System.out.println("Element not found");
            else
                System.out.println("Element found at index " + ans);
        }


}