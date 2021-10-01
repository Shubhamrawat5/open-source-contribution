#include <iostream>
using namespace std;
bool isPairSum(int A[], int N, int X){	
	int i = 0;	
	int j = N - 1;
	while (i < j) {	
		if (A[i] + A[j] == X)
			return true;	
		else if (A[i] + A[j] < X)
			i++;
		else
			j--;
	}
	return false;
}

int main(){
	int arr[] = { 3, 5, 9, 2, 8, 10, 11 };
	int val = 17;	
	int arrSize = sizeof(arr)/ sizeof(arr[0]);	
	if(isPairSum(arr, arrSize, val)){
        cout<<"Yes ,there exist a pair of numbers";
    }else{
        cout<<"No such pairs exist";
    }
	return 0;
}
