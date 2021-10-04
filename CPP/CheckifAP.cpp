#include <iostream>
using namespace std;

bool isAP(int arr[], int n){
  if(n==1){
    return true;
  }
  int d = arr[1]-arr[0];
  for(int i=2;i<n;i++){
    if(arr[i]-arr[i-1] != d){
      return false;
    }
  }
  return true;
}

int main(){
  int arr[5] = {6,7,8,9,10};
  int n = sizeof(arr)/sizeof(arr[0]);
  if(isAP(arr,n)){
    cout<<"YES";
  }
  else{
    cout<<"NO";
  }
}
