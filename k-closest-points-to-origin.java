class Solution {
    
    
    //Runtime: 27 ms , Time Complexity -  O(n log (k)) 
    public int[][] kClosest(int[][] points, int k) {
        
        int arrLength = points.length;
        
       Queue<int[]> maxHeap = new PriorityQueue<>(new Comparator<int[]>(){
           @Override
           public int compare(int[] arr1, int[] arr2){
               return (getEuclideanDistance(arr2) - getEuclideanDistance(arr1));
           }
       });
        
        for(int[] point : points){
            maxHeap.add(point);
            if(maxHeap.size() > k){
                maxHeap.remove();
            }
        }
        
        int[][] result = new int[k][2];
        
        while(k > 0){
            result[--k] = maxHeap.poll();
        }
        
        return result;
    }
    
   /*
    * The distance between two points on the X-Y plane is the Euclidean distance (i.e., v(x1 - x2)2 + (y1 - y2)2).
    * For us one of the point (0,0) which is origin so, the other point will be
    *  v(x1 - 0)2 + (y1 - 0)2). >> (x1 * x1 + y1 * y1) 
    *. Ignoring the Square root as we are just comparing.
    */
    public int getEuclideanDistance(int[] arr){
        return (arr[0] * arr[0] + arr[1] * arr[1]);
    }
}