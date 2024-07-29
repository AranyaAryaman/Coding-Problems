/*
Majority Element
Programming
Greedy Algorithm
Easy
52.5% Success

582

50

Bookmark
Asked In:
Problem Description
 
 

Given an array of size N, find the majority element. The majority element is the element that appears more than floor(N/2) times.
You may assume that the array is non-empty and the majority element always exist in the array.



Problem Constraints
1 <= |A| <= 106
1 <= Ai <= 109


Input Format
The first argument is an integer array A.


Output Format
Return the majority element.


Example Input
A = [2, 1, 2]


Example Output
2


Example Explanation
2 occurs 2 times which is greater than 3/2.
*/

int Solution::majorityElement(const vector<int> &A) {
    int n = A.size();
    if(n==1 || n==2)    return A[0];
    unordered_map<int,int> myMap;
    for(int i=0;i<A.size();i++){
        if(myMap.find(A[i])!=myMap.end()){
            myMap[A[i]]++;
            if(myMap[A[i]]>= n/2 + 1)
                return A[i];
        }
        else
            myMap.insert(make_pair(A[i],1));
    }
}
