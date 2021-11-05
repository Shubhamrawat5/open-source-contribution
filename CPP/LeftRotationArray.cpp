#include <bits/stdc++.h>

using namespace std;

void rotateone(int n , int d ,int a[]){
    int temp = a[0] ; 
    for(int i = 0 ; i < n ;i++){
        a[i] = a[i+1];
    }
    a[n-1] = temp ;
}

void leftrotate(int n , int d ,int a[]){
    for(int i = 0 ; i < d ; i++){
        rotateone(n , d ,a );
    }
}
int main()
{
    int n , d ; 
    cin >> n >>  d  ;
    int a[n ]; 
    for(int i = 0 ; i < n ; i++){
        cin >> a[i] ;
    }
    leftrotate(n , d , a) ;
    for(int i = 0 ; i < n ; i++){
        cout << a[i] <<" "; 
    }
}
