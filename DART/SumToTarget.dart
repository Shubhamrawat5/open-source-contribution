void main() {
  int target = 9;

  List array = [2, 7, 11, 15];

  List result = _getIndices(array, target);
  print(result);
}

List _getIndices(List array, target) {
  int arrSize = array.length;

  /* The idea is to store the complement of numbers starting from index 0 and check
   * wheather the complement is present in the elements of the array*/
  List storage = [(target - array[0])];
  int storageSize;
  bool found = false;
  int i, j;
  for (i = 0; i < arrSize; i++) {
    if (i == 0) {
      continue;
    }
    storageSize = storage.length;
    for (j = 0; j < storageSize; j++) {
      if (array[i] == storage[j]) {
        found = true;
        break;
      }
      storage.add((target - array[i]));
    }

    if (found == true) {
      break;
    }
  }
  return [j, i];
}
