/*
Rain Water Trapped
Programming
Stacks And Queues
Hard
67.3% Success

444

7

Bookmark
Asked In:
Problem Description

Given an integer array A of non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.



Problem Constraints
1 <= |A| <= 100000



Input Format
The only argument given is integer array A.



Output Format
Return the total water it is able to trap after raining.



Example Input
Input 1:

 A = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
Input 2:

 A = [1, 2]


Example Output
Output 1:

 6
Output 2:

 0
*/

int Solution::trap(const vector<int> &A) {
    if(A.size()==0 || A.size()==1 || A.size()==2)
        return 0;
    vector<int> left(A.size());
    vector<int> right(A.size());
    left[0]=A[0]; 
    right[A.size()-1]=A[A.size()-1];
    for(int i=1;i<A.size();i++){
        left[i]=A[i]>=left[i-1]?A[i]:left[i-1];
    }
    for(int i=A.size()-2;i>=0;i--){
        right[i]=A[i]>=right[i+1]?A[i]:right[i+1];
    }
    int waterTrapped = 0;
    for(int i=1;i<A.size()-1;i++){
        waterTrapped += max(min(left[i],right[i])-A[i],0);
    }
    return waterTrapped;
}
