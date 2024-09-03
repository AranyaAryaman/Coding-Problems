/*
Highest Product
Programming
Greedy Algorithm
easy
37.1% Success

209

31

Bookmark
Asked In:
Problem Description
 
 

Given an array A, of N integers A.
Return the highest product possible by multiplying 3 numbers from the array.
NOTE: The solution will fit in a 32-bit signed integer.


Problem Constraints
3 <= N <= 5*105


Input Format
The first and the only argument is an integer array A.


Output Format
Return the highest possible product.


Example Input
Input 1:
A = [1, 2, 3, 4]
Input 2:
A = [0, -1, 3, 100, 70, 50]


Example Output
Output 1:
24
Output 1:
350000


Example Explanation
Explanation 1:
2 * 3 * 4 = 24
Explanation 2:
70 * 50 * 100 = 350000
*/

int Solution::maxp3(vector<int> &A) {
    sort(A.begin(),A.end());
    int n = A.size()-1;
    int lastThree = A[n]*A[n-1]*A[n-2];
    int firstTwoAndLast = A[n]*A[0]*A[1];
    return max(lastThree,firstTwoAndLast);
}
