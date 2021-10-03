#include<bits/stdc++.h>
using namespace std;
int hcf(int num1,int num2){
	int r=min(num1,num2);
	while(r!=0){
		if(num1%r==0 && num2%r==0)
		break;
		r--;
	}
	return r;

}
int main(){
	cout<<"hcf="<<hcf(8,18);
	return 0;
}