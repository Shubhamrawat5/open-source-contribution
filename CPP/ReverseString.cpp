// A simple C++ program to reverse string using constructor
#include <bits/stdc++.h>
using namespace std;
int main(){

	string str = "GeeksforGeeks";
	int n=str.length();
	//Temporary string to store the reverse
	string rev;
	for(int i=n-1;i>=0;i--)
	rev.push_back(str[i]);

	cout<<rev<<endl;
	return 0;
}
