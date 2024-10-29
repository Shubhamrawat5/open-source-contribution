class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        int n=s2.size();
        int arr[26]= {0};
        int i=0,j=0;
        int ct=s1.size();
        for(int i=0;i<s1.size();i++)
        {
            arr[s1[i]-'a']++;
        }
        while(j<n)
        {
            if(arr[s2[j]-'a']>0)
            {
                ct--;
            }
            arr[s2[j]-'a']--;
            j++;
            if(ct==0) return true;
            if(j-i==s1.size())
            {
                if(arr[s2[i]-'a']>=0)
                {
                    ct++;
                   
                }
                arr[s2[i]-'a']++;
                i++;
            }
            
        }
        return false;
    }
};
