#include<iomanip>
#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
        int maxProfit(vector<int>& days){
            int max_profit=0;
            for(int i = 0 ; i < days.size();i++){
                if(days[i]>days[i-1]){
                    max_profit+=days[i]-days[i-1];
                }
            }
            return max_profit;
        }
};

int main(){
    int no_days;
    cout << "Enter the number of days: ";
    cin >> no_days;
    vector<int> days(no_days);
    cout<<"Enter the prices for each days : ";
    for(int i=0; i<no_days;i++){
        cin >> days[i]; 
    }
    Solution sol;
    cout<<"Maximum profit in a "<<no_days<<" days : ";
    cout<<sol.maxProfit(days);
}