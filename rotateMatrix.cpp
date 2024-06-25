/*
Problem Description
 
 

You are given a N x N 2D matrix A representing an image.

Rotate the image by 90 degrees (clockwise).

You need to do this in place. Update the given matrix A.

Note: If you end up using an additional array, you will only receive a partial score.



Problem Constraints
1 <= N <= 1000



Input Format
First argument is a 2D matrix A of integers



Output Format
Rotate the given 2D matrix A.
*/

void Solution::rotate(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    for(int i=0;i<n/2;i++){
        for(int j=i;j<n-i-1;j++){
            int temp = A[i][j];
            A[i][j]=A[n-1-j][i];
            A[n-1-j][i]=A[n-1-i][n-1-j];
            A[n - 1 - i][n - 1 - j] = A[j][n - 1 - i];
            A[j][n - 1 - i] = temp;
        }
    }
}
