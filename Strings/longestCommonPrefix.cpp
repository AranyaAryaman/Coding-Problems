/*
Problem Description
 
 

Given the array of strings A, you need to find the longest string S which is the prefix of ALL the strings in the array.

Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.

For Example: longest common prefix of "abcdefgh" and "abcefgh" is "abc".



Problem Constraints
0 <= sum of length of all strings <= 1000000



Input Format
The only argument given is an array of strings A.



Output Format
Return the longest common prefix of all strings in A.



Example Input
Input 1:

A = ["abcdefgh", "aefghijk", "abcefgh"]
Input 2:

A = ["abab", "ab", "abcd"];
*/

bool comp(string s1, string s2){
    return s1.length()<s2.length();
}

string Solution::longestCommonPrefix(vector<string> &A) {
    sort(A.begin(),A.end(),comp);
    for(int len=A[0].length();len>=0;len--){
        int count = 0;
        string str = A[0].substr(0,len);
        for(int j=1;j<A.size();j++){
            if(A[j].find(str)==string::npos)
                break;
            else
                count++;
        }
        if(count==A.size()-1)
            return str;
    }
    return "";  
}
