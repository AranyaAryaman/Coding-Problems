/*
Problem Description
 
 

You are given a 2D string array A of dimensions N x 2,

where each row consists of two strings: first is the name of the student, second is their marks.

You have to find the maximum average mark. If it is a floating point, round it down to the nearest integer less than or equal to the number.



Problem Constraints
1 <= N <= 105


Input Format
The first argument is a 2D string array A.


Output Format
Return a single integer which is the highest average mark.


Example Input
Input 1:
A = [["Bob", "80"], ["Bob", "90"], ["Alice", "90"]]
Input 2:

A = [["Bob", "80"], ["Bob", "90"], ["Alice", "90"], ["Alice", "10"]]


Example Output
Output 1:
90
Output 2:

85
*/

int Solution::highestScore(vector<vector<string> > &A) {
    unordered_map<string,pair<int,int>> scores;
    int highestAverage = INT_MIN;
    for(int i=0;i<A.size();i++){
        if(scores.find(A[i][0])!=scores.end()){
            auto pos = scores.find(A[i][0]);
            int curr_score = pos->second.first + stoi(A[i][1]);
            int curr_subjects = pos->second.second + 1;
            int curr_average = (int)(curr_score/curr_subjects);
            scores.erase(A[i][0]);
            //cout<<curr_score<<" "<<curr_subjects<<" "<<curr_average<<endl;
            scores.insert(make_pair(A[i][0],make_pair(curr_score,curr_subjects))); 
        }
        else{
            scores.insert(make_pair(A[i][0],make_pair(stoi(A[i][1]),1)));
            //cout<<"Here:"<<stoi(A[i][1])<<endl;
        }
    }
    unordered_map<string,pair<int,int>>::iterator it;
    for(it=scores.begin();it!=scores.end();it++){
        highestAverage = max(highestAverage, (int)(it->second.first/it->second.second));
    }
    return highestAverage;
}
