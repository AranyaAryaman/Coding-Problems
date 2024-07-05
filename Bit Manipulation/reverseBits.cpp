/*
Problem Description

Reverse the bits of an 32 bit unsigned integer A.



Problem Constraints
0 <= A <= 232



Input Format
First and only argument of input contains an integer A.



Output Format
Return a single unsigned integer denoting the decimal value of reversed bits.



Example Input
Input 1:

 0
Input 2:

 3


Example Output
Output 1:

 0
Output 2:

 3221225472
*/

unsigned int Solution::reverse(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> bitA;
    while(A!=0){
        bitA.push_back(A%2);
        A=A/2;
    }
    for(int i=bitA.size();i<32;i++)
        bitA.push_back(0);
    int x=0;
    for(int i=0;i<32;i++){
        x += pow(2,31-i)*bitA[i];
    }
    return (unsigned int) x;
}
