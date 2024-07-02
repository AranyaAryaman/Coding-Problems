/*
Problem Description
 
 

Given a positive integer that fits in a 32-bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0.
A and P both should be integers.


Problem Constraints
1 <= A <= 109


Input Format
The first argument is an integer A.


Output Format
Return an integer, 1 for True, 0 for False


Example Input
A = 4


Example Output
1


Example Explanation
A = 4, it can be written as 2 ^ 2
*/

int Solution::isPower(int A) {
    for(int i=1;i<=sqrt(A)+1;i++){
        for(int j=2;j<=32;j++){
            if(pow(i,j)==A)
                return 1;
            else if(pow(i,j)>A)
                break;
            else
                continue;
        }
    }
    return 0;
}
