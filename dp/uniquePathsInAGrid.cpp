/*
Unique Paths in a Grid
Programming
Dynamic Programming
medium
35.7% Success

171

12

Bookmark
Asked In:
Given a grid of size m * n, lets assume you are starting at (1,1) and your goal is to reach (m,n). At any instance, if you are on (x,y), you can either go to (x, y + 1) or (x + 1, y).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Example :

There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

bool isValid(int r, int c, vector<vector<int> > &A){
    if(r<A.size() && r>=0 && c<A[0].size() && c>=0 && A[r][c]!=1)
        return true;
    return false;
}

int numberPaths( int r, int c, vector<vector<int> >&A, vector<vector<int> >&dp){
    if(isValid(r,c,A) && dp[r][c]!=-1)
        return dp[r][c];
    if(r==A.size()-1 && c==A[0].size()-1)
        return 1;
    else{
        int x=0;
        if(isValid(r+1,c,A))
            x += numberPaths(r+1,c,A,dp);
        if(isValid(r,c+1,A))
            x += numberPaths(r,c+1,A,dp);
        dp[r][c]=x;
        return x;
    }
}

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    if(A[A.size()-1][A[0].size()-1]==1 || A[0][0]==1)
        return 0;
    vector<vector<int> >dp(A.size(),vector<int>(A[0].size(),-1));
    return numberPaths(0,0,A,dp);
    
}
