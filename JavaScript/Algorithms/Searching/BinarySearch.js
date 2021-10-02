/* 
************* Binary Search ************
It is a searching algorithm that can search in 0(log n) time for a sorted array compared to linear search's O(n) time for an unsorted array
It only works on sorted array and is able to search that array much faster than linear Search due to the presort
*/

/* 
Pseudo Code
1. Create a left pointer index that starts at 0
2. Create a right pointer index that starts at length od array -1
3. While left pointer is less than or equal to right pointer,
 3.1 Calculate middle index(round down or up) and then middle value
 3.2 If middle value is equal to value, return middle index
 3.3. If middle value too large, move right pointer down 
4. Return -1 (since value never found in while loop)
*/

const binarySearch = (sortedArr, value) => {
  let left = 0;

  let right = sortedArr.length - 1;

  while (left <= right) {
    const mid = Math.floor((left + right) / 2);

    const midVal = sortedArr[mid];

    if (midVal === value) {
      return mid;
    } else if (midVal < value) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1;
};

//  Time Complexity ======> O(log n)
