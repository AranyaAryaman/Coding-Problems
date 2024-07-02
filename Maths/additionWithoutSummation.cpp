/*
Problem Description
 
 

You are given two numbers A and B.

You have to add them without using arithmetic operators and return their sum.



Problem Constraints
1 <= A, B <= 109


Input Format
The first argument is the integer A. The second argument is the integer B.


Output Format
Return a single integer denoting their sum.


Example Input
Input 1:
A = 3
B = 10
Input 2:

A = 6
B = 1


Example Output
Output 1:
13
Output 2:

7
*/

#include<bitset>

int bitAdd(bitset<32> A, bitset<32> B){
    bool carry=0;
    bitset<33> ans;
    for(int i=0;i<32;i++){
        ans[i] = ((A[i]^B[i])^carry);
        carry = (A[i]&&B[i] || B[i]&&carry || A[i]&&carry);
    }
    return (int) ans.to_ulong();
}

int Solution::addNumbers(int A, int B) {
    bitset<32> bitA(A);
    bitset<32> bitB(B);
    return bitAdd(A,B);
}
