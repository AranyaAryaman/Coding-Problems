/*
Problem Description
 
 

Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].



Problem Constraints
1 <= |A| <= 106
-109 <= Ai <= 109


Input Format
First and only argument is an integer array A.



Output Format
Return an integer denoting the maximum value of j - i;



Example Input
Input 1:

 A = [3, 5, 4, 2]
*/

bool comp(pair<int,int> p1, pair<int, int> p2){
    return p1.first==p2.first?p1.second<p2.second:p1.first<p2.first;
}

int Solution::maximumGap(const vector<int> &A) {
    vector<pair<int,int>> temp;
    for(int i=0;i<A.size();i++)
        temp.push_back({A[i],i});
    sort(temp.begin(),temp.end(),comp); 
    int ans = 0;
    int idx_max = temp[temp.size()-1].second;
    for(int i=temp.size()-2;i>=0;i--){
        ans = max(ans,(idx_max - temp[i].second));
        idx_max = max(idx_max,temp[i].second);
    }
    return ans;
}
