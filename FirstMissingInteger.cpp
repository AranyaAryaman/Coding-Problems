/*
Problem Constraints
1 <= |A| <= 106
-106 <= Ai <= 106


Input Format
The first argument is an integer array A.


Output Format
Return an integer equal to the first missing positive integer


Example Input
Input 1:
A = [1,2,0]
Input 2:
A = [3,4,-1,1]
Input 3:
A = [-8,-7,-6]


Example Output
Output 1:
3
Output 2:
2
Output 3:
1
*/

int Solution::firstMissingPositive(vector<int> &A) {
    int ans = 1;
    int start = 0;
    for(int i=0;i<A.size();i++){
        if(A[i]<=0){
            swap(A[i],A[start]);
            start++;
        }
    }
    if(start == A.size()){
        return ans;
    }
    for(int i=start;i<A.size();i++){
        if(start+abs(A[i])-1<A.size() && start+abs(A[i])-1>=0){
            A[start+abs(A[i])-1]*= -1;
        }
    }
    for(int i=start;i<A.size();i++){
        if(A[i]>0)
            break;
        else
            ans++;
    }
    return ans;
}
