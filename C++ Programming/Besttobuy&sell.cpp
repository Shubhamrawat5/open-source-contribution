#include<iostream>
#include<iomanip>
#include<vector>
#include<climits>
using namespace std;
class Solution{
    public:
    int max_profit(vector<int> &prices){
        int min_price=INT_MAX;
        int max_profit=0;
        for(int price : prices){
            min_price=min(min_price,price);
            int profit=price-min_price;
            max_profit=max(max_profit,profit);
        }
        return max_profit;
    } 
};

int main()
{
    int size;
    cout<<"Enter the size of the array : ";
    cin>>size;
    vector<int> prices(size);
    cout<<"Enter the elements in the array : ";
    for(int i = 0 ; i < size ; i++){
        cin>>prices[i];
    }
    Solution sol;
    int max_p=sol.max_profit(prices);
    cout<<"Max Profit : "<<max_p;
    return 0;
}