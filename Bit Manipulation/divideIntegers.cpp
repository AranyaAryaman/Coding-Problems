/*
Problem Description
 
 

Divide two integers A and B, without using multiplication, division, and mod operator.
Return the floor of the result of the division.

Also, consider if there can be overflow cases. For overflow cases, return INT_MAX.
Note: INT_MAX = 2^31 - 1


Problem Constraints
INT_MIN <= A, B <= INT_MAX
B != 0


Input Format
The first argument is an integer A.
The second argument is an integer B.


Output Format
Return an integer equal to A / B.


Example Input
A = 5
B = 2


Example Output
2
*/


int Solution::divide(int A, int B) {
    if(A==0)    return 0;

    long long int dividend = A;
    long long int divisor = B;
    
    bool sign = (dividend<0 ^ divisor<0)?true:false;
    dividend = abs(dividend);
    divisor = abs(divisor);
    long long int temp = 0, quotient = 0;
    for(int i=31;i>=0;i--){
        if(temp + (divisor<<i)<= dividend){
            temp += divisor<<i;
            quotient |= 1LL<<i;
        }
    }
    if(sign) quotient = -quotient;
    if(quotient<INT_MIN)    quotient = INT_MIN;
    if(quotient>INT_MAX)    quotient = INT_MAX;
    return quotient;
}
