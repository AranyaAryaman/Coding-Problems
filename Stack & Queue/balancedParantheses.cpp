/*
Balanced Parantheses!
Programming
Stacks And Queues
Easy
75.3% Success

240

5

Bookmark
Asked In:
Problem Description

Given a string A consisting only of '(' and ')'.

You need to find whether parantheses in A is balanced or not ,if it is balanced then return 1 else return 0.



Problem Constraints
1 <= |A| <= 105



Input Format
First argument is an string A.



Output Format
Return 1 if parantheses in string are balanced else return 0.



Example Input
Input 1:

 A = "(()())"
Input 2:

 A = "(()"


Example Output
Output 1:

 1
Output 2:

 0
*/

int Solution::solve(string A) {
    if(A.length()==0 || A.length()==1)   return A.length()-1;
    stack<char> st;
    for(int i=0;i<A.length();i++){
        if(A[i]=='('){
            st.push('(');
        }
        else{
            if(st.empty())
                return 0;
            else
                st.pop();
        }
    }
    if(st.empty())
        return 1;
    else
        return 0;
    
}
