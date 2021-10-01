#include <bits/stdc++.h>

#include <iostream>

using namespace std;

//#define int long long

template <class temp> //or we can write like this template<template temp
temp mymax(temp x, temp y)
{
    return (x > y) ? x : y;
}
int main()
{
    cout << "maxx is : " << mymax<int>(10, 18) << endl;
    cout << "maxx is : " << mymax<char>('A', 'a') << endl;
    cout << "maxx is : " << mymax<float>(10.4, 10.5) << endl;
    return 0;
}