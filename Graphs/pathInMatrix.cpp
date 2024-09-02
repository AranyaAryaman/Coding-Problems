/*
Path in Matrix
Programming
Graph Data Structure & Algorithms
medium
62.3% Success

71

24

Bookmark
Asked In:
Problem Description
 
 

Given N x N matrix filled with 0, 1, 2, 3.

Find whether there is a path possible from source to destination, traversing through blank cells only. 
 
You can traverse up, down, right, and left. Return a single integer 1 if a path exists, otherwise 0.

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Blank Wall.
Note: there are an only a single source and single destination(sink).


Problem Constraints
2 <= N <= 103
0 <= Ai, j <= 3


Input Format
The first argument is the 2D integer array A.


Output Format
Return a single integer 1 if a path exists, otherwise 0.


Example Input
Input 1:
A = [[1, 0], [0, 2]]
Input 2:

A = [[1, 3], [3, 2]]


Example Output
Output 1:
0
Output 2:

1


Example Explanation
Explanation 1:
The source is blocked by walls on all its sides. So, there is no way to reach the destination.
Explanation 2:

We can take any possible path to reach the destination from the source.
*/

bool isValid(int i, int j, vector<vector<int> >&A){
    if(i>=0 && i<A.size() && j>=0 && j<A[0].size())
        return true;
    else
        return false;
}

bool hasPath(int src_i, int src_j, int dst_i, int dst_j, vector<vector<int> >&visited, vector<vector<int> >& A){
    if(src_i == dst_i && src_j == dst_j)
        return true;
    if(!isValid(src_i,src_j,A)) 
        return false;
    if(visited[src_i][src_j]==1 || A[src_i][src_j]==0)
        return false;
    visited[src_i][src_j]=1;
    return  hasPath(src_i+1,src_j,dst_i,dst_j,visited,A) || 
            hasPath(src_i-1,src_j,dst_i,dst_j,visited,A) ||   
            hasPath(src_i,src_j+1,dst_i,dst_j,visited,A) || 
            hasPath(src_i,src_j-1,dst_i,dst_j,visited,A);
}

int Solution::checkPath(vector<vector<int> > &A) {
    vector<vector<int>> visited(A.size(),vector<int>(A[0].size()));
    int src_i, src_j, dst_i, dst_j;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A.size();j++){
            if(A[i][j]==1){
                src_i = i;
                src_j = j;
            }
            if(A[i][j]==2){
                dst_i = i;
                dst_j = j;
            }
        }
    }
    return hasPath(src_i,src_j,dst_i,dst_j, visited,A)==true?1:0;
}
