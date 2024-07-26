/*
Connect Ropes
Programming
Heaps And Maps
Medium
84.3% Success

69

5

Bookmark
Problem Description
 
 

Given an array of integers A representing the length of ropes.

You need to connect these ropes into one rope. The cost of connecting two ropes is equal to the sum of their lengths.

Find and return the minimum cost to connect these ropes into one rope.



Problem Constraints
1 <= length of the array <= 100000

1 <= A[i] <= 1000



Input Format
The only argument given is the integer array A.



Output Format
Return an integer denoting the minimum cost to connect these ropes into one rope.



Example Input
Input 1:

 A = [1, 2, 3, 4, 5]
Input 2:

 A = [5, 17, 100, 11]


Example Output
Output 1:

 33
Output 2:

 182
*/

int Solution::solve(vector<int> &A) {
    // cout<<"Yay";
    priority_queue <int, vector<int>, greater<int>> pq;
    // cout<<"Here";
    for(int i=0;i<A.size();i++){
        pq.push(A[i]);
    }
    int cost = 0;
    while(!pq.empty()){
        int firstNum = pq.top();
        pq.pop();
        if(!pq.empty()){
            int secondNum = pq.top();
            pq.pop();
            int localCost = firstNum + secondNum;
            cost += localCost;
            pq.push(localCost);
        }
        else
            break;
    }
    return cost;
}
