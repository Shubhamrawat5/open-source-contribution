/*
    Richa-15
    Find if a subset exists such that subset sum mod k is zero
*/


#include<bits/stdc++.h>
using namespace std;

bool subModM(vector<int>& arr, int k){
    map<int, int> ma;

    ma.insert(make_pair(0,1));

    int csum = 0, count = 0, rem;

    for(auto x: arr){
        csum += x;
        rem = csum % k;

        rem = (rem<0) ? k + rem : rem;

        if(ma.find(rem) != ma.end())
            //count += ma[rem];         //count no. of subsets
            return true;                // return when first subset is found
        else
            ma.insert(make_pair(rem,0));

        ma[rem]++;
    }

    if(count){
            cout<<"count:"<<count<<endl;
        return true;
    }

    return false;
}


int main(){
    vector<int> arr = {3, 1, 8, 7};
    int k = 6;
    subModM(arr, k) ? cout<<"subset found\n" : cout<<"no subset found\n";
    return 0;
}
