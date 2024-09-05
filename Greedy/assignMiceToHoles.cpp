/*
Problem Description

There are N Mice and N holes that are placed in a straight line. Each hole can accomodate only 1 mouse.

The positions of Mice are denoted by array A and the position of holes are denoted by array B.

A mouse can stay at his position, move one step right from x to x + 1, or move one step left from x to x − 1. Any of these moves consumes 1 minute.

Assign mice to holes so that the time when the last mouse gets inside a hole is minimized.



Problem Constraints
1 <= N <= 105

-109 <= A[i], B[i] <= 109



Input Format
First argument is an integer array A.

Second argument is an integer array B.



Output Format
Return an integer denoting the minimum time when the last nouse gets inside the holes.
*/

int Solution::mice(vector<int> &A, vector<int> &B) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int total = 0;
    for(int i=0;i<A.size();i++){
        total = max(total,abs(A[i]-B[i]));
    }
    return total;
}
