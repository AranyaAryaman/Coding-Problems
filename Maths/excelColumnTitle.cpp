/*
Problem Description

Given a positive integer A, return its corresponding column title as appear in an Excel sheet.



Problem Constraints
1 <= A <= 1000000000



Input Format
First and only argument is integer A.



Output Format
Return a string, the answer to the problem.



Example Input
Input 1:

 A = 1
Input 2:

 A = 28


Example Output
Output 1:

 "A"
Output 2:

 "AB"
  */

string Solution::convertToTitle(int A) {
    string ans="";
    while(A!=0){
        int rem = A%26; 
        int toConvert = (int)('A');
        char toAdd;
        if(rem==0){
            toAdd = 'Z';
            A = A/26 - 1;
        }
        else{
            toAdd = (char)(toConvert + rem - 1);
            A = A/26; 
        }
        ans = toAdd + ans;
        //cout<<"rem:"<<rem<<" toAdd:"<<toAdd<<" A:"<<A<<" ans:"<<ans<<endl; 
    }
    return ans;
}
