// CPP program find with subarray with guven sum

#include<iostream>
using namespace std;

int subArraySum(int arr[], int n, int sum){

    int curr_sum=0;
    for(int i=0;i<n;i++){
        curr_sum=arr[i];

        for(int j=i+1;j<n;j++){
            if(curr_sum==sum){
                cout << i << " " << j-1;
                return 1;
            }
            if(curr_sum>sum){
                break;
            }
            curr_sum+=arr[j];
        }
    }
    cout << "not found" << endl;
    return 0;

}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = 5;
    int sum = 9;

    subArraySum(arr,n,sum);
}

// optimised approach


int subArraySum(int arr[], int n, int sum){

    int curr_sum = arr[0], start = 0, i;
    for(i=1; i<=n; i++){
        while(curr_sum > sum && start < i-1){ 
            curr_sum = curr_sum - arr[start];
            start++;
        }
        if(curr_sum == sum){
            cout << start << " " << i-1 << endl;
            return 1;
        }
        if(i<n){
            curr_sum += arr[i];
        }

    }
    cout << "No subarray";
    return 0;
}



int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = 5;
    int sum = 1;

    subArraySum(arr,n,sum);
}

