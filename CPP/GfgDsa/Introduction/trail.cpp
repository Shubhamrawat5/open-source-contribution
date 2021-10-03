//Program to find trailing zero of the factorial
#include<bits/stdc++.h>
using namespace std;
long long int Factorial(int n){
	int p=1;
	for(int i=1;i<=n;i++){
		p=p*i;
	}
	return p;
}
int Zero(long long int s){
	int count=0;
	while(s%10==0){
		count ++;
		s=s/10;
	}
	return count;
}
int main(){
	long long int a=Factorial(12);
	cout<<"Factorail of a="<<a<<"\n";
	cout<<"No. of zeros are="<<Zero(a);
	return 0;
}