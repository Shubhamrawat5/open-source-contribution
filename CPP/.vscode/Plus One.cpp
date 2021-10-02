#include<bits/stdc++.h>
using namespace std;
    vector<int> plusOne(vector<int>& digits) {
        //int f=1;
        int i;
         for(i=digits.size()-1;i>=0;i--)
         {
            //digits[i]+=f;
             digits[i]++;
            if(digits[i]>9)
            {
                digits[i]=digits[i]%10;
              //  f=1;
            }
            else
            {
                break;
            }
         }
        i=0;
        if(digits[i]==0)
        {
            vector<int> res;
            res.push_back(1);
            for(int j=0;j<digits.size();j++)
            {
                res.push_back(digits[j]);
            }
            return res;
        }
        return digits;
    }
int main()
{
   return plusOne({4,3,2,1})  ;
}