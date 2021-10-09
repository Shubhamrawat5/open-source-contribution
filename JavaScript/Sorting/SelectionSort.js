let selectionSort = (arr) => {

   //Loop till the second last element
   for(let i = 0; i < arr.length - 1; i++){

      //Loop after the i till the last element
      for(let j = i + 1; j < arr.length; j++){

         //if jth element is less than the ith element then swap
         //change < to > for sorting in descending order
         if(arr[j] < arr[i]){
           let temp = arr[i];
           arr[i] = arr[j];
           arr[j] = temp;
         }

      }

   }
   
   //return the sorted array
   return arr;
}
