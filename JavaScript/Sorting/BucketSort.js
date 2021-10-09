const bucketSort = (arr, n = arr.length) => {
  //Create a bucket array
  let bucket = new Array(n);
  
  //Add bucket group
  for(let i = 0; i < n; i++){
    bucket[i] = [];
  }
  
  //Add the elements in a same range in bucket
  for(let i = 0; i < n; i++){
    let bucketIndex = Math.floor(arr[i]) * n;
    bucket[bucketIndex].push(arr[i]);
  }
  
  //Sort each bucket separately
  for(let i = 0; i < n; i++){
    bucket[i].sort();
  }
  
  // Get the sorted array
  let index = 0;
  for (let i = 0; i < n; i++) {
    for (let j = 0, size = bucket[i].length; j < size; j++) {
        arr[index++] = bucket[i][j];
    }
  }
}

const sortMixed = (arr, n = arr.length) => {
  const neg = [];
  const pos = [];
  
  //Group the positive and negative values
  for(let i = 0; i < n; i++){
    if(arr[i] < 0){
      neg.push(-1 * arr[i]);
    }else{
      pos.push(arr[i]);
    }
  }
  
  //sort the group
  bucketSort(neg);
  bucketSort(pos);
  
  // First store elements of Neg[] array 
  // by converting into -ve 
  for (let i = 0; i < neg.length; i++){ 
      arr[i] = -1 * neg[ neg.length - 1 - i];
  }
  
  // store +ve element 
  for(let j = neg.length; j < n; j++) {
      arr[j] = pos[j - neg.length]; 
  }
} 
