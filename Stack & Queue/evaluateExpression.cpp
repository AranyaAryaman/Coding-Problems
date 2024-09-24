/*
Evaluate Expression
Programming
Stacks And Queues
easy
55.4% Success

226

19

Bookmark
Asked In:
Problem Description
 
 

An arithmetic expression is given by a string array A of size N. Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each string may be an integer or an operator.



Problem Constraints
1 <= N <= 105



Input Format
The only argument given is string array A.



Output Format
Return the value of arithmetic expression formed using reverse Polish Notation.



Example Input
Input 1:
    A =   ["2", "1", "+", "3", "*"]
Input 2:
    A = ["4", "13", "5", "/", "+"]


Example Output
Output 1:
    9
Output 2:
    6


Example Explanation
Explaination 1:
    starting from backside:
    * : () * ()
    3 : () * (3)
    + : (() + ()) * (3)
    1 : (() + (1)) * (3)
    2 : ((2) + (1)) * (3)
    ((2) + (1)) * (3) = 9
Explaination 2:
    + : () + ()
    / : () + (() / ())
    5 : () + (() / (5))
    13 : () + ((13) / (5))
    4 : (4) + ((13) / (5))
    (4) + ((13) / (5)) = 6
*/

bool isOperator(string c){
    if(c=="+" || c=="-" || c=="*" || c=="/")
        return true;
    else
        return false;
}

int Solution::evalRPN(vector<string> &A) {
    if(A.size()==1)
        return stoi((string)A[0]);
    stack<string> st;
    int num = 0;
    
    for(int i=0;i<A.size();i++){
        if(isOperator(A[i])){         
            string a = st.top();
            int x = stoi(a);
            //cout<<x<<" ";
            //cout<<A[i]<<" ";
            st.pop();
            string b = st.top();
            int y = stoi(b);
            //cout<<y<<" ";
            st.pop();
            if(A[i]=="+")
                num = y + x; 
            else if(A[i]=="-")
                num = y - x; 
            else if(A[i]=="*")
                num = y * x; 
            else
                num = y/x;
            st.push(to_string(num));
        }
        else{
            st.push(A[i]);
        }
    }
    return num;
}
