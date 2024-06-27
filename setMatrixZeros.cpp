/*
Problem Description
 
 

Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.
Note: This will be evaluated on the extra memory used. Try to minimize the space and time complexity.



Problem Constraints
1 <= N, M <= 1000
0 <= A[i][j] <= 1


Input Format
The first and the only argument of input contains a 2-d integer matrix, A, of size M x N.


Output Format
Return a 2-d matrix that satisfies the given conditions.


Example Input
Input 1:
[   [1, 0, 1],
    [1, 1, 1], 
    [1, 1, 1]   ]
Input 2:
[   [1, 0, 1],
    [1, 1, 1],
    [1, 0, 1]   ]


Example Output
Output 1:
[   [0, 0, 0],
    [1, 0, 1],
    [1, 0, 1]   ]
Output 2:
[   [0, 0, 0],
    [1, 0, 1],
    [0, 0, 0]   ]
*/

void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    bool firstRow = false;
    bool firstCol = false;
    if(A[0][0]==0){
        firstRow = true;
        firstCol = true;
    }
    
    for(int i=0;i<A.size();i++){
        if(A[i][0]==0){
            firstCol = true;
            break;
        }
    }
    
    for(int i=0;i<A[0].size();i++){
        if(A[0][i]==0){
            firstRow = true;
            break;
        }
    }
         
    
    for(int i=1;i<A.size();i++){
        for(int j=1;j<A[i].size();j++){
            if(A[i][j]==0){
                A[i][0]=0;
                A[0][j]=0;
            }
        }
    }
    
    for(int i=1;i<A.size();i++){
        if(A[i][0]==0){
            for(int j=1;j<A[i].size();j++){
                A[i][j]=0;
            }
        }
    }
    
    for(int i=1;i<A[0].size();i++){
        if(A[0][i]==0){
            for(int j=1;j<A.size();j++){
                A[j][i]=0;
            }
        }
    }
    
    if(firstRow){
        for(int i=0;i<A[0].size();i++)
            A[0][i]=0;
    }
    
    if(firstCol){
        for(int i=0;i<A.size();i++)
            A[i][0]=0;
    }
}
