/*
Problem Description
 
 

Given an integer A, equal to numRows, generate the first numRows of Pascal's triangle.
Pascal's triangle: To generate A[C] in row R, sum up A'[C] and A'[C-1] from the previous row R - 1.



Problem Constraints
0 <= A <= 25


Input Format
The first argument is an integer A, equal to the numRows.


Output Format
Return an array of array of integers, equal to pascal triangle.


Example Input
A = 5


Example Output
[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]
*/

vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> res;
    if(A==0)
        return res;
    vector<int> temp;
    temp.push_back(1);
    res.push_back(temp);
    if(A==1)    return res;
    temp.push_back(1);
    res.push_back(temp);
    if(A==2)    return res;
    for(int i=2;i<A;i++){
        vector<int> temp2;
        temp2.push_back(1);
        for(int j=0;j+1<i;j++){
            temp2.push_back(res[i-1][j]+res[i-1][j+1]);
        }
        temp2.push_back(1);
        res.push_back(temp2);
        temp2.clear();
    }
    return res;
}
