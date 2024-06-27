/*
Problem Description
 
 

Find the contiguous subarray within an array, A of length N which has the largest sum.


Problem Constraints
1 <= N <= 106
-1000 <= A[i] <= 1000


Input Format
The first and the only argument contains an integer array, A.


Output Format
Return an integer representing the maximum possible sum of the contiguous subarray.
*/

int Solution::maxSubArray(const vector<int> &A) {
    int max_sum = INT_MIN;
    int curr_sum = 0;
    for(int i=0;i<A.size();i++){
        curr_sum += A[i];
        max_sum = max(curr_sum, max_sum);
        if(curr_sum<0)
            curr_sum = 0;
    }
    return max_sum;
}
