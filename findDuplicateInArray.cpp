/*
Problem Description
 
 

Given a read-only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.
If there are multiple possible answers ( like in the sample case ), output any one, if there is no duplicate, output -1



Problem Constraints
1 <= |A| <= 105
1 <= Ai <= |A|


Input Format
The first argument is an integer array A.


Output Format
Return the integer that repeats in array A
*/

int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    vector<int> visited(n+1,0);
    for(int i=0;i<A.size();i++){
        if(visited[A[i]]>0)
            return A[i];
        else
            visited[A[i]]++;
    }
    return -1;
}
