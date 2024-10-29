/** 
* Author :- [Ashish Kumar Sahoo](github.com/ashish5kmax)
* leetcode daily problem date:-08/10/2024

* Approch:-
  1) The intution we get here is that this problem is similar to that of valid parenthesis I would say basically a follow up of that problem.
  2) So, we use stack here to remove all the "[]" substring from the stack and keep only "][" type parts of string. 
     eg:-  s="[][]]][[", stk = "]][[".
  3) Now, we observe that whenever the stack is empty that means no swap is required as it's already balenced but if not then we see no. of "]][[" present in stack and % it with 4 if it's reminder is '0' that means our ans is = stk.size()/4 or else its stk.size()/4+1.
  4) The reason we divide it with 4 is I have noticed a pattern that is whenver we have "]][[" or "]]][[[" we swap stk.size()/4 for even and stk.size()/4+1 for odd, times only and its true and verified that's why. 

* Coding Execution Performace :-
  TIme:- O(N)
  Space:- O(N) (Stack Space)

* Thank you!!. 
* Happy to contribute.
**/ 

class Solution {
public:
    int minSwaps(string s) {
        // faster i/o access to achive higher speed of execution.
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // stack to maintain the char input when '[' pop when ']'
        stack<char>stk;
        int n = s.size();

        for(int i=0;i<n;i++) {
            if(!stk.empty() && stk.top()=='[' && s[i]==']') {
                stk.pop();
            }
            else {
                stk.push(s[i]);
            }
        }

        // check size of size%4 even return size/4 or else size/4+1
        return stk.size()%4==0 ? stk.size()/4 : stk.size()/4+1;
    }
};
