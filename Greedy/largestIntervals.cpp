/*
Largest Permutation
Programming
Greedy Algorithm
easy
36.9% Success

218

19

Bookmark
Asked In:
Problem Description

Given an integer array A of size N consisting of unique integers from 1 to N. You can swap any two integers atmost B times.

Return the largest lexicographical value array that can be created by executing atmost B swaps.



Problem Constraints
1 <= N <= 106

1 <= B <= 109



Input Format
First argument is an integer array A of size N.

Second argument is an integer B.



Output Format
Return an integer array denoting the largest lexicographical value array that can be created by executing atmost B swaps.



Example Input
Input 1:

 A = [1, 2, 3, 4]
 B = 1
Input 2:

 A = [3, 2, 1]
 B = 2


Example Output
Output 1:

 [4, 2, 3, 1]
Output 2:

 [3, 2, 1]


Example Explanation
Explanation 1:

 In one swap we can swap (1, 4) so that the array becomes : [4, 2, 3, 1].
Explanation 2:

 Array is already the largest lexicographical value array.
*/

vector<int> Solution::solve(vector<int> &A, int B) {
    vector<int> desc = A;
    for(int i=0;i<A.size();i++)
        desc[i]=A.size()-i;
    unordered_map<int,int> myMapActual;
    for(int i=0;i<A.size();i++){
        myMapActual[A[i]]=i;
    }
    int i=0;
    while(B>0 && i<A.size()){
        if(desc[i]==A[i])
            i++;
        else{
            int nextHigherNumber = desc[i];
            int replacementNumber = A[i];
            int actualLocationNextHigher = myMapActual[desc[i]];
            int replacementLocation = i;
            swap(A[replacementLocation],A[actualLocationNextHigher]);
            myMapActual[nextHigherNumber]=replacementLocation;
            myMapActual[replacementNumber]=actualLocationNextHigher;
            i++;
            B--;
        }    
    }
    return A;    
}
