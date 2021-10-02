//To understand about the problem, check
//https://www.hackerrank.com/challenges/chocolate-feast/problem

#include<bits/stdc++.h>
using namespace std;

int* wrappers(int a, int b){
    static int wrap_count[2]={0, 0};
    //until number of wrapper more than number of wrappers require to turn into bar
    //means loop until wrappers are sufficient to exchange
    while(a>=b){
        wrap_count[0]++;
        a=b-a;
    }
    wrap_count[1] = a;
    return wrap_count;
}

int main(){

    //number of test cases
    int t;
    cin >> t;

    while(t--){
        //n = initial amount of money
        //c = the cost of one chocolate bar
        //m = number of wrappers he can turn into one bar
        int n, c, m;
        cin >> n >> c >> m;

        int tot_chocolate = n/c;
        cout << "\nTotal chocolate that can be bought: " << tot_chocolate;

        int* get_wrapper = wrappers(tot_chocolate, m);
        cout << "\nTotal bars he can get in exchange " << get_wrapper[0] << " remaining wrappers " << get_wrapper[1];
        cout << "\n";


    }
    return 0;
}