/*
Merge K sorted arrays!
Programming
Heaps And Maps
medium
73.3% Success

195

14

Bookmark
Asked In:
Problem Description

You are given K sorted integer arrays in a form of 2D integer matrix A of size K X N.

You need to merge them into a single array and return it.



Problem Constraints
1 <= K, N <= 103

0 <= A[i][j] <= 108

A[i][j] <= A[i][j+1]



Input Format
First and only argument is an 2D integer matrix A.



Output Format
Return a integer array denoting the merged array you get after merging all the arrays in A.



Example Input
Input 1:

 A = [  [1, 2, 3]
        [2, 4, 6]
        [0, 9, 10]
     ]


Example Output
Output 1:

 [0, 1, 2, 2, 3, 4, 6, 9, 10]


Example Explanation
Explanation 1:

 You need to merge [1, 2, 3] , [2, 4, 6] and [0, 9, 10]  into a single array
 so the merged array will look like [0, 1, 2, 2, 3, 4, 6, 9, 10]
*/

struct comp{
    bool operator()(int a, int b){
        return a>b;
    }   
};


vector<int> Solution::solve(vector<vector<int> > &A) {
    priority_queue<int,vector<int>,comp> q;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[i].size();j++){
            q.push(A[i][j]);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        ans.push_back(q.top());
        q.pop();
    }
    return ans;
}
