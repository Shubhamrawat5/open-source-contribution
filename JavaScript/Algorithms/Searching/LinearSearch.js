/*
************ Linear Search ************
A Searching algorithm that searches by manually checking everything in the data set to see if it is the value we are searching for
It finds what we are searching for by brute force, making it easy to implement
*/

/*
Implement Linear Search Algorithm that search a provided array for the provided value
The Linear search algorithm will either return boolean index, or value back
const foods = ['pizza', 'orange', 'yoghurt']
linearSearchIndexOf(foods, 'pizza') =====> 0
linearSearchIncludes(foods, 'pizza') =====> true
linearSearchFind(foods, food => food === 'pizza') =====> 'pizza'
*/

function linearSearchIndexOf(arr, val) {
  for (let i = 0; i < arr.length; i++) {
    if (val === arr[i]) return i;
  }
  return -1;
}

function linearSearchIncludes(arr, val) {
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] === val) {
      return true;
    }
  }
}

function linearSearchFind(arr, func) {
  for (let i = 0; i < arr.length; i++) {
    if (func(arr[i]) === true) {
      return arr[i];
    }
  }
  return undefined;
}

// BigO ===> O(N)
