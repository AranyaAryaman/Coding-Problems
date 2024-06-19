/*
Problem Description

Given an array of integers, A of length N, find out the maximum sum sub-array of non negative numbers from A.

The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array.

Find and return the required subarray.

NOTE:  

If there is a tie, then compare with segment's length and return segment which has maximum length.
If there is still a tie, then return the segment with minimum starting index.


Problem Constraints
1 <= N <= 105

-109 <= A[i] <= 109



Input Format
The first and the only argument of input contains an integer array A, of length N.



Output Format
Return an array of integers, that is a subarray of A that satisfies the given conditions.
*/

vector<int> Solution::maxset(vector<int> &A) {
    long long int max_sum = INT_MIN;
    long long int curr_sum = 0;
    long long int max_idx;
    vector<vector<int> >positives;
    vector<int> temp;
    for(int i=0;i<A.size();i++){
        if(A[i]<0){
            positives.push_back(temp);
            temp.clear();
            if(curr_sum > max_sum){
                max_sum = curr_sum;
                max_idx = positives.size()-1;
            }
            curr_sum = 0;
            continue; 
        }
        else{
            curr_sum += A[i];
            temp.push_back(A[i]);
        }
        
        if(i==A.size()-1){
            positives.push_back(temp);
            if(curr_sum > max_sum){
                max_sum = curr_sum;
                max_idx = positives.size()-1;
            }
        } 
    }
    return positives[max_idx];
}
