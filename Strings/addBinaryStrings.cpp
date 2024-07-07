/*
Problem Description
 
 

Given two binary strings A and B. Return their sum (also a binary string).


Problem Constraints
1 <= length of A <= 105

1 <= length of B <= 105

A and B are binary strings



Input Format
The two argument A and B are binary strings.



Output Format
Return a binary string denoting the sum of A and B



Example Input
Input 1:
A = "100"
B = "11"
Input 2:
A = "110"
B = "10"


Example Output
Output 1:
"111"
Output 2:
"1000"
*/

string Solution::addBinary(string A, string B) {
    string ans = "";
    int carry = 0;
    int val;
    int i = A.length()-1;
    int j = B.length()-1;
    int aVal, bVal;
    //cout<<A.length()<<" "<<B.length()<<endl;
    while(i>=0 && j>=0){
        if(A[i]=='0')
            aVal = 0;
        if(B[j]=='0')
            bVal = 0;
        if(A[i]=='1')
            aVal = 1;
        if(B[j]=='1')
            bVal = 1;
        val = (aVal + bVal + carry)%2;
        carry = (aVal + bVal + carry)/2;
        ans = to_string(val) + ans;
        i--;
        j--;
    }
    //cout<<i<<" "<<j<<endl;
    while(i>=0){
        if(A[i]=='0')
            aVal = 0;
        if(A[i]=='1')
            aVal = 1;
        val = (aVal+carry)%2;
        carry = (aVal+carry)/2;
        ans = to_string(val) + ans;
        i--;
    }
    while(j>=0){
        if(B[j]=='0')
            bVal = 0;
        if(B[j]=='1')
            bVal = 1;
        val = (bVal+carry)%2;
        carry = (bVal+carry)/2;
        ans = to_string(val) + ans;
        j--;
    }
    if(carry==1){
        ans = to_string(carry) + ans;
    }
    if(ans[0]=='-') return ans.substr(1);
    return ans;
}
