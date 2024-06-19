/*
Problem Description
 
 

You are given an integer array A.

You have to find the number of occurences of each number.

Return an array containing only the occurences with the smallest value's occurence first.

For example, A = [4, 3, 3], you have to return an array [2, 1], where 2 is the number of occurences for element 3, 
and 1 is the number of occurences for element 4. But, 2 comes first because 3 is smaller than 4.



Problem Constraints
1 <= |A| <= 105
1 <= Ai <= 109


Input Format
The first argument is the integer array A.


Output Format
Return an integer array denoting the occurences of each number.
*/

vector<int> Solution::findOccurences(vector<int> &A) {
    map<long long int,long long int> myMap;
    for(int i=0;i<A.size();i++){
        if(myMap.find(A[i])!=myMap.end())
            myMap[A[i]]++;
        else{
            myMap.insert(make_pair(A[i],1));
        }
    }
    vector<int> res;
    map<long long int, long long int>::iterator it=myMap.begin();
    while(it!=myMap.end()){
        res.push_back(it->second);
        it++;
    }
    return res;
}
