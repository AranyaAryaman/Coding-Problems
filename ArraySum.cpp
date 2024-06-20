/*
Problem Description
 
 

You are given two numbers represented as integer arrays A and B, where each digit is an element.
 You have to return an array which representing the sum of the two given numbers.

The last element denotes the least significant bit, and the first element denotes the most significant bit.

Note : Array A and Array B can be of different size. ( i.e. length of Array A may not be equal to length of Array B ).



Problem Constraints
1 <= |A|, |B| <= 105
0 <= Ai, Bi <= 9


Input Format
The first argument is an integer array A. The second argument is an integer array B.


Output Format
Return an array denoting the sum of the two numbers.
  */

vector<int> Solution::addArrays(vector<int> &A, vector<int> &B) {
    int m = A.size();
    int n = B.size();
    int carry=0;
    vector<int> ans;
    stack<int> s; 
    for(int i=0;i<min(m,n);i++){
        s.push((A[m-1-i]+B[n-1-i]+carry)%10);
        carry = (A[m-1-i]+B[n-1-i]+carry)/10;
    }
    if(m<n){
        for(int i=n-m-1;i>=0;i--){
            s.push((B[i]+carry)%10);
            carry = (B[i]+carry)/10;
        }
        if(carry>0)
            s.push(carry);
    }
    if(n<m){
        for(int i=m-n-1;i>=0;i--){
            s.push((A[i]+carry)%10);
            carry = (A[i]+carry)/10;
        }
        if(carry>0)
            s.push(carry);
    }
    if(carry>0)
        s.push(carry);
    bool firstNumberFound = false;
    while(!s.empty()){
        int x = s.top();
        if(firstNumberFound){
            ans.push_back(x);
            s.pop();
        }
        else{
            if(x==0)
                s.pop();
            else{
                ans.push_back(x);
                s.pop();
                firstNumberFound = true;
            }
        }    
    }
    return ans;  
}
