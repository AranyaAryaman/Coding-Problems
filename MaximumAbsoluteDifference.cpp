/*
You are given an array of N integers, A1, A2 ,..., AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N. f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.


Problem Constraints
1 <= |A| <= 105
-109 <= Ai <= 109


Input Format
The first argument is an integer array A.


Output Format
Return an integer equal to the maximum value of f(i, j)
*/

int Solution::maxArr(vector<int> &A) {
    vector<int> temp1;
    vector<int> temp2;
    for(int i=0;i<A.size();i++){
        temp1.push_back(A[i]-i);
        temp2.push_back(A[i]+i);
    }
    sort(temp1.begin(),temp1.end());
    sort(temp2.begin(),temp2.end());
    int val1 = abs(temp1[temp1.size()-1]-temp1[0]);
    int val2 = abs(temp2[temp1.size()-1]-temp2[0]);    
    return max(val1,val2);
    
}
