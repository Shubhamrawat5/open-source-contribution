#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    string exp;
    cin >> exp;
    stack<int> st;
    int temp;
    for(auto it : exp)
    {
        if(isalpha(it))
        {
            cin >> temp;
            st.push(temp);
        }
        else
        {
            if(it == '+')
            {
                int k = st.top();
                st.pop();
                k += st.top();
                st.pop();
                st.push(k);
            }
            else if(it == '-')
            {
                int k = st.top();
                st.pop();
                k -= st.top();
                st.pop();
                st.push(k);
            }
            else if(it == '*')
            {
                int k = st.top();
                st.pop();
                k *= st.top();
                st.pop();
                st.push(k);
            }
            else if(it == '/')
            {
                int k = st.top();
                st.pop();
                k /= st.top();
                st.pop();
                st.push(k);
            }
        }
    }
    cout << st.top();
    return 0;
}
