/*given pattern:
1
11
21
1211
111221
*/

//Input:10
//Output:13211311123113112211


#include <iostream>
#include<vector>
using namespace std;

int main() 
{
    int n;
    cin>>n;
    int temp=1;
    vector <int> s;
    s.push_back(1);
    s.push_back(1);
    vector<int> stemp;
    int count;
    int ch;
    n-=2;

    while(n--)
    {
        count=0;
        ch=s[0];
        for(int i=0;i<=s.size();i++)
        {
             if(s[i]==ch)
             {
                 count+=1;
             }
             else 
             {
                 stemp.push_back(count);
                 stemp.push_back(ch);

                 ch=s[i];
                 i--;
                 count=0;
             }
        }

        s=stemp;

        stemp.clear();
        for(int i=0;i<stemp.size();i++)
            cout<<stemp[i];

    }
    for(int i=0;i<s.size();i++)
    cout<<s[i];
    cout<<endl;

	return 0;
}
