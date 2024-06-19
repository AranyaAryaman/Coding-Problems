/*
Problem Description
 
 

Given a non-negative number represented as an array of digits, add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer. For example: 
for this problem, following are some good questions to ask :

Q : Can the input have 0's before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
A : For the purpose of this question, YES
Q : Can the output have 0's before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.


Problem Constraints
1 <= |A| <= 106
0 <= Ai <= 9


Input Format
First argument is an array of digits.



Output Format
Return the array of digits after adding one.

*/

vector<int> Solution::plusOne(vector<int> &A) {
    int sum;
    int carry = 1;
    stack<int> s;
    for(int i=A.size()-1;i>=0;i--){
        sum = (A[i]+carry)%10;
        carry = (A[i]+carry)/10;
        s.push(sum); 
    }
    if(carry==1)
        s.push(carry);
    vector<int> res;
    bool foundFirstNumber = false;
    while(!s.empty()){
        int top = s.top();
        s.pop();
        if(foundFirstNumber){
            res.push_back(top);
        }
        else{
            if(top>0){
                foundFirstNumber = true;
                res.push_back(top);
            }
        }
    }
    return res;
}
