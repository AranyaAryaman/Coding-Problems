/*
Gas Station
Programming
Greedy Algorithm
Medium
33.4% Success

602

24

Bookmark
Asked In:
Problem Description
 
 

Given two integer arrays A and B of size N. There are N gas stations along a circular route, where the amount of gas at station i is A[i].

You have a car with an unlimited gas tank and it costs B[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the minimum starting gas station's index if you can travel around the circuit once, otherwise return -1.

You can only travel in one direction. i to i+1, i+2, ... n-1, 0, 1, 2.. Completing the circuit means starting at i and ending up at i again.


Problem Constraints
1 <= |A| <= 5 * 105
|A| == |B|
0 <= Ai <= 5 * 103
0 <= Bi <= 5 * 103


Input Format
The first argument given is the integer array A. The second argument given is the integer array B.


Output Format
Return the minimum starting gas station's index if you can travel around the circuit once, otherwise return -1.


Example Input
A = [1, 2]
B = [2, 1]


Example Output
1


Example Explanation
If you start from index 0, you can fill in A[0] = 1 amount of gas.
Now your tank has 1 unit of gas. But you need B[0] = 2 gas to travel to station 1.

If you start from index 1, you can fill in A[1] = 2 amount of gas.
Now your tank has 2 units of gas. You need B[1] = 1 gas to get to station 0.
So, you travel to station 0 and still have 1 unit of gas left over.
You fill in A[0] = 1 unit of additional gas, making your current gas = 2. It costs you B[0] = 2 to get to station 1, which you do and complete the circuit.

*/

// int Solution::canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
//     // if(A.size()==1)
//     //     return A[0]>=B[0]?0:-1;
//     // int n = A.size();
//     // int curr_fuel = 0;
//     // int curr_count = 0;
//     // for(int i=0;i<n;i++){
//     //     curr_fuel = A[i]-B[i];
//     //     curr_count = 1;
//     //     int j = i+1;
//     //     //cout<<i<<": ";
//     //     while(curr_fuel>=0 && j!=i){
//     //         curr_fuel += A[j%n] - B[j%n];
//     //         //cout<<j<<" "<<curr_fuel<<endl;
//     //         if(curr_fuel>0){
//     //             curr_count++;
//     //             j = (j+1)%n;
//     //         }   
//     //     }
//     //     if(j==i || curr_count==n)
//     //         return i;
//     // }
//     // return -1;
//     int n=gas.size();
//     int total=0,surplus=0,idx=0;
//     for(int i=0;i<n;i++){
//         total+=gas[i]-cost[i];
//         surplus+=gas[i]-cost[i];
//         if(surplus<0){
//             idx=i+1;
//             surplus=0;
//         }
//     }
//     return (total>=0) ? idx:-1;
    
// }

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    vector<int> gas(2*A.size()),cost(2*A.size());
    for(int i=0;i<gas.size();i++){
        gas[i]=A[i%A.size()];
        cost[i]=B[i%A.size()];        
    }
    int start = 0, curr=0;
    for(int i=0;i<gas.size();i++){
        if(i==start+A.size())
            return start;
        curr+=gas[i]-cost[i];
        if(curr<0){
            curr=0;
            start=i+1;
        }
    }
    return -1;
}
