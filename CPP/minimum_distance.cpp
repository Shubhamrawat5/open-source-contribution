//To checkout the problem statement, visit
//https://www.hackerrank.com/challenges/minimum-distances/problem
//contributed by AnuragYadav365

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];

    //getting values of integer array
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int min = 1000;
    int temp = 0;

    //loop for combining pairs
    //loop through array from 0 index to n-1
    for(int j=0; j<n-1; j++){
        //loop through array from 1 index to n
        for(int k=j+1; k<n; k++){

            //if match found
            if(a[j] == a[k]){
                //compute difference in index of both element
                temp = k - j;

                //if difference is less than current minimum difference
                //replace the minimum
                if(temp < min){
                    min = temp;
                }
            }
        }
    }

    //if match found then temp must not be eqaul to 0
    //so print minimum
    if(temp != 0){
        cout << min;
    }

    //if no match found
    //to return -1
    else{
        cout << -1;
    }
    return 0;
}