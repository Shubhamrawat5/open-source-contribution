#include <bits/stdc++.h>
using namespace std;
int digitIteration(int n)
{
	int count = 0;
	while (n != 0)
	{
		n = n / 10;
		++count;
	}
	return count;
}
int recursion(int n)
{
	if (n == 0)
		return 0;
	return 1 + recursion(n / 10);
}
int main()
{
	cout << "Iteration method:" << digitIteration(123) << endl;
	cout << "Recusion method:" << recursion(123);
	return 0;
}