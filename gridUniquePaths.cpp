/*
Robot is located at the top-left corner of an A x B grid (marked ‘Start’ in the diagram below).

Path Sum: Example 1

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked ‘Finish’ in the diagram below).

How many possible unique paths are there?

Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.

Example :

Input : A = 2, B = 2
Output : 2

2 possible routes : (0, 0) -> (0, 1) -> (1, 1) 
              OR  : (0, 0) -> (1, 0) -> (1, 1)
*/

int Solution::uniquePaths(int A, int B) {
    A = A-1;
    B = B-1;
    double tempAnsQuotient=1.0;
    double tempAnsRemainer=1.0;
    double tempAns=1.0;
    if(B>A) swap(A,B);
    for(int i=1;i<=B;i++){
        tempAnsQuotient *= (double)(i+A);
        tempAnsRemainer *= (double)i;  
        tempAns *= ((double)(i+A)/(double)i);
    }
    
    if(((int)(tempAns * 10)%10)>=5)  return (int) tempAns + 1;
    else return (int) tempAns;
}
