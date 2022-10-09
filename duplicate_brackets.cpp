#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"testcases\n";
    int t;
    cin>>t;
    while(t--)
    {
      cout<<"Enter string\n";
      string x;
      cin>>x;
      int i=0;
      stack<char>st;
      bool flag =1;
      while(x[i]!='\0')
      {
        if(x[i]==')')
        {
            if(st.top()=='(')
            {
                cout<<"Duplicate brackets\n";
                flag=0;
                 break;
            }
            else
            {
                while(st.top()!='(') //assumed that brackets are perfectly balanced
                st.pop();
               
            }
            st.pop();
        }
        else
        {
            st.push(x[i]);
        }
        i++;
      }
      if(flag)
      cout<<"No Duplicate brackets"<<endl;
   }
    

}
