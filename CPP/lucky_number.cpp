//To checkout the problem statement, visit
//https://codeforces.com/problemset/problem/110/A
//contributed by AnuragYadav365

#include<bits\stdc++.h>
using namespace std;

int main(){
    long long int n;
    cin >> n;

    int luckycnt = 0;
    while(n>0){
        //cout << "n%10  " << n%10 <<endl;
        if(n%10 == 7 or n%10 == 4){
            luckycnt+=1;
        }
        //cout << "n/10 is  " << n/10 <<endl;
        n = n/10;
    }
    cout << ((luckycnt == 7 or luckycnt == 4)? "YES":"NO");
    return 0;
}