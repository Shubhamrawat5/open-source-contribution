class Solution {
  //Declare the sum variable as global...  
  int sum ;
    public int rangeSumBST(TreeNode root, int low, int high) {
        sum = 0;
        
        traverse(root, low, high);
        return sum;
    }
    public void traverse(TreeNode root, int low, int high){
        if(root != null){
            if(root.val >= low && root.val <= high){
                sum += root.val;
            }
            if(root.val > low){
                traverse(root.left, low, high);
            }
            if(root.val < high){
                traverse(root.right, low, high);
            }
        }
    }
    
}

//Better than 100% solutions
