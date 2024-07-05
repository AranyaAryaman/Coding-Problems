/*
Problem Description
 
 

Given an array of integers A, every element appears twice except for one. Find that single one.


NOTE: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?



Problem Constraints
1 <= |A| <= 2000000

0 <= A[i] <= INTMAX



Input Format
First and only argument of input contains an integer array A.



Output Format
Return a single integer denoting the single element.
*/

int Solution::singleNumber(const vector<int> &A) {
    int ans = A[0];
    for(int i=1;i<A.size();i++){
        ans = ans ^ A[i];
    }
    return ans;
}
