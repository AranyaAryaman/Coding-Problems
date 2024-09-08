/*
Word Search Board
Programming
Graph Data Structure & Algorithms
hard
26.4% Success

276

42

Bookmark
Asked In:
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The cell itself does not count as an adjacent cell. 

The same letter cell may be used more than once.

Example :

Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns 1,
word = "SEE", -> returns 1,
word = "ABCB", -> returns 1,
word = "ABFSAB" -> returns 1
word = "ABCD" -> returns 0
Note that 1 corresponds to true, and 0 corresponds to false.
*/

bool isValid(int r, int c, vector<vector<char> >& A){
    if(r>=0 && r<A.size() && c>=0 && c<A[0].size())
        return true;
    else
        return false;
}

bool findExistence(vector<vector<char> >& A, string B, int i, int j){
    if(B.length()==0)
        return true;
    if(!isValid(i,j,A))
        return false;
    if(B.length()==1 && A[i][j]==B[0])
        return true;
    if(B.length()==1 && A[i][j]!=B[0])
        return false;
    if(A[i][j]==B[0]){
        return findExistence(A,B.substr(1),i+1,j) 
        || findExistence(A,B.substr(1),i-1,j) 
        || findExistence(A,B.substr(1),i,j+1) 
        || findExistence(A,B.substr(1),i,j-1);
    }
    else
        return false;
}

int Solution::exist(vector<string> &A, string B) {
    if(B.length()==0)
        return 1;
    vector<vector<char> >arr(A.size(), vector<char> (A[0].size()));
    for(int i=0;i<A.size();i++){
        int j = 0;
        while(j<A[i].length()){
            arr[i][j]= A[i][j];
            j++;
        }
    } 
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            if(findExistence(arr,B,i,j))
                return 1;
        }
    }
    return 0;
}
