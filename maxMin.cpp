/*
Problem Description

Given an array A of size N. You need to find the sum of Maximum and Minimum element in the given array.

NOTE: You should make minimum number of comparisons.



Problem Constraints
1 <= N <= 105

-109 <= A[i] <= 109



Input Format
First and only argument is an integer array A of size N.
*/

int Solution::solve(vector<int> &A) {
    int min_elem = INT_MAX;
    int max_elem = INT_MIN;
    for(int i=0;i<A.size();i++){
        min_elem = min(min_elem, A[i]);
        max_elem = max(max_elem, A[i]);
    }
    return max_elem + min_elem;
    
}
