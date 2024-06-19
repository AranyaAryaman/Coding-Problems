/*
Problem Description
You are in an infinite 2D grid where you can move in any of the 8 directions

 (x,y) to 
    (x-1, y-1), 
    (x-1, y)  , 
    (x-1, y+1), 
    (x  , y-1),
    (x  , y+1), 
    (x+1, y-1), 
    (x+1, y)  , 
    (x+1, y+1) 
You are given a sequence of points and the order in which you need to cover the points.. Give the minimum number of steps in which you can achieve it. You start from the first point.

NOTE: This question is intentionally left slightly vague. Clarify the question by trying out a few cases in the “See Expected Output” section.



Problem Constraints
1 <= |A| <= 106
- 2 * 103 <= Ai, Bi <= 2 * 103
|A| == |B|


Input Format
Given two integer arrays A and B, where A[i] is x coordinate and B[i] is y coordinate of ith point respectively.
*/


int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int ans=0;
    for(int i=1;i<A.size();i++){
        int x1 = A[i-1];
        int x2 = A[i];
        int y1 = B[i-1];
        int y2 = B[i];
        ans += max(abs(x2-x1),abs(y2-y1));
    }
    return ans;
}
