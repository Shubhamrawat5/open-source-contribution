#Game Description

Suppose you are participating in a Dancing competition. The dance performance will be done on a linear stage marked with integral positions.
Initially, your are present at position X and your dance partner is at position Y. You can perform two kinds of dance moves.

If your are currently at position k, you can:

Moonwalk to position k+2, or
Slide to position k−1
You want to find the minimum number of moves required to reach your partner. Can you find this number?

##Input Format
First line will contain a single integer T, the number of testcases. Then the description of T testcases follows.
Each testcase contains a single line with two space-separated integers X,Y, representing the initial positions of you and your dance partner, respectively.

##Output Format
For each testcase, print in a separate line, a single integer, the minimum number of moves required by you to reach your dance partner.

Constraints
1≤T≤103
−103≤X,Y≤103
Sample Input 1 
4
3 8
-11 -5
57 492
-677 913
Sample Output 1 
4
3
219
795
Explanation
Test Case 1: You will perform Moonwalk thrice, followed by a slide reaching at position 8. This makes 4 dance steps in total.
Test Case 2: Performing Moonwalk thrice will take you to your dance partner.