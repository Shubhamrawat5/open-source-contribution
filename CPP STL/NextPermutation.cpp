/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

Leetcode Problem 31. Next Permutation - https://leetcode.com/problems/next-permutation/

*/

class Solution {
    public void nextPermutation(int[] nums) {
        int size = nums.length, k=0;
        for (k=size-2; k>=0; k--) {
            if (nums[k]<nums[k+1])
                break;
        }
        if (k<0)
            Arrays.sort(nums);
        else {
            int l;
            for (l=size-1; l>k; l--) {
                if (nums[l]>nums[k])
                    break;
            }
            swap(nums, k, l);            
            reverse(nums, k+1);
        }
    }
    
    private void reverse(int[] nums, int start) {
        int i=start, j=nums.length-1;
        while(i<j) {
            swap(nums,i,j);
            i++;
            j--;
        }
    }
    
    private void swap(int[] nums,int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
}
