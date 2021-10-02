//To checkout the problem statement, visit
//https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true
//contributed by AnuragYadav365

#include<bits/stdc++.h>
using namespace std;

int main(){
    //size of chocolate bar having integers
    int n;
    cin >> n;

    int s[n];
    //storing integers written on each sqaure of chocolate bar
    for(int i=0; i<n; i++){
        cin >> s[i];
    }

    //d is Ron's birthdate
    //m is Ron's birth month
    int d, m;
    cin >> d >> m;

    //segment count that he can sare with his friend
    int segment_cnt =0;
    int i=0;

    //runs through s upto n-1
    while(i!=(n-1)){
        //for summing up the cnt of segment pieces
        int cnt=0;
        for(int j=i; j<i+m;j++){
            //cout << "elements is: " << s[j];
            cnt+=s[j];
        }

        //if the count matches with the birthdate of Ron
        //then this segment is valid
        if(cnt==d){
            segment_cnt++;
        }

        //increment the starting index continuosly
        //after checking each segment
        i++;
    }

    //if there is no segment match
    if(segment_cnt==0 and n>1){
        cout << 0;
    }

    //if no segment match and also there is only one swaure of chocolate bar
    else if(segment_cnt==0 and n==1){
        if(d==s[0] and m==n){
            cout << m;
        }

        else{
            cout << 0;
        }
    }

    //if there are enough valid segments
    //output the segment count
    else{
        cout << segment_cnt;
    }
    return 0;
}