/*
Problem Description
 
 

Given an integer array A, move all 0's to the end of it while maintaining the relative order of the non-zero elements.


Note that you must do this in-place without making a copy of the array.



Problem Constraints
1 <= |A| <= 105


Input Format
First argument is array of integers A.


Output Format
Return an array of integers which satisfies above property.
*/

vector<int> Solution::solve(vector<int> &A) {
    int zeroCount = 0;
    vector<int> ans;
    for(int i=0;i<A.size();i++){
        if(A[i]==0)
            zeroCount++;
        else
            ans.push_back(A[i]);
    }
    while(zeroCount>0){
        ans.push_back(0);
        zeroCount--;
    }
    return ans;
}
