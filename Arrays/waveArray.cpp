/*
Problem Description
 
 

Given an array of integers A, sort the array into a wave-like array and return it. 
In other words, arrange the elements into a sequence such that

a1 >= a2 <= a3 >= a4 <= a5..... 
NOTE: If multiple answers are possible, return the lexicographically smallest one.



Problem Constraints
1 <= len(A) <= 106

1 <= A[i] <= 106



Input Format
The first argument is an integer array A.



Output Format
Return an array arranged in the sequence as described.
*/

vector<int> Solution::wave(vector<int> &A) {
    vector<int> ans;
    sort(A.begin(),A.end());
    if(A.size()%2==1){
        for(int i=0;i<A.size()-1;i++){
            if(i%2==0){
                ans.push_back(A[i+1]);
            }
            else{
                ans.push_back(A[i-1]);
            }
        }
        ans.push_back(A[A.size()-1]);
    }
    else{
        for(int i=0;i<A.size();i++){
            if(i%2==0){
                ans.push_back(A[i+1]);
            }
            else{
                ans.push_back(A[i-1]);
            }
        }
    }
    return ans;
}
