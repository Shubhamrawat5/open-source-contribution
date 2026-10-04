int sum(int target, int arr)
{
  int l = 0;
  int h = arr.size()-1;
  if(l<=h)
  {
    int mid = (l+h)/2;
    if(arr[mid]==target)
    {
      return mid;
    }
    else if(arr[mid]<target)
    {
      l = mid+1;
    }
    else{
      h = mid-1;
  }
    return -1;
}
