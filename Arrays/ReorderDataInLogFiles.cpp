/*
Problem Description
 
 

You are given an array of logs. Each log is a space-delimited string of words, where the first word is the identifier.

There are two types of logs:

Letter-logs: All words (except the identifier) consist of lowercase English letters.
Digit-logs: All words (except the identifier) consist of digits.

Reorder these logs so that:

The letter-logs come before all digit-logs.
The letter-logs are sorted lexicographically by their contents. If their contents are the same, then sort them lexicographically by their identifiers.
The digit-logs maintain their relative ordering.

Return the final order of the logs.


Problem Constraints
1 <= logs.length <= 1000
3 <= logs[i].length <= 1000
All the tokens of logs[i] are separated by a single space.
logs[i] is guaranteed to have an identifier and at least one word after the identifier.


Input Format
The first argument is a string array A where each element is a log.


Output Format
Return the string array A after making the changes.
*/

bool comp(string s1, string s2){
    int log1Pos = s1.find("-");
    int log2Pos = s2.find("-");
    string log1 = s1.substr(log1Pos+1);
    string log2 = s2.substr(log2Pos+1);
    if(log1!=log2)
        return log1<log2;
    else
        return s1<s2;
}

vector<string> Solution::reorderLogs(vector<string> &A) {
    vector<string> ans;
    vector<string> letterLogs;
    vector<string> digitLogs;
    for(int i=0;i<A.size();i++){
        int blank = A[i].find('-');
        if(A[i][blank+1]>='a' && A[i][blank+1]<='z'){
            letterLogs.push_back(A[i]);
        } 
        else{
            digitLogs.push_back(A[i]);
        }
    }
    sort(letterLogs.begin(),letterLogs.end(),comp);
    for(int i=0;i<letterLogs.size();i++){
        ans.push_back(letterLogs[i]);
    }
    for(int i=0;i<digitLogs.size();i++){
        ans.push_back(digitLogs[i]);
    }
    return ans;
}
