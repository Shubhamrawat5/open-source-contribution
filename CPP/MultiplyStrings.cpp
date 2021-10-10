// Leetcode Problem 43 : https://leetcode.com/problems/multiply-strings/

class Solution {
public:
    string multiply(string num1, string num2) {
        
        int s1 = num1.size(), s2 = num2.size();
        
        if( (s1==1 && num1=="0") || (s2==1 && num2=="0") )
            return "0";
        
        string res(s1+s2, '0') ;
        
        for(int i=s1-1; i>=0; i--)
        {
            int carry=0;
            for(int j=s2-1; j>=0; j--)
            {
                int mul = (num2[j]-'0')*(num1[i]-'0') + (res[i+j+1] -'0') + carry;
                carry = mul/10;
                res[i+j+1] = '0'+mul%10;
            }
            res[i]= carry+'0';
        }
    
        int pos = 0;
        for( pos=0; pos<(s1+s2); pos++)
            if(res[pos]!='0')
                break;
        
        return res.substr(pos);
        
    }
};
