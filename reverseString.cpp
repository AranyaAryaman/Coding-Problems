/*
Problem Description
 
 

You are given a string A of size N.

 

Return the string A after reversing the string word by word.

NOTE:

A sequence of non-space characters constitutes a word.
Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
If there are multiple spaces between words, reduce them to a single space in the reversed string.
 



Problem Constraints
1 <= N <= 3 * 105



Input Format
The only argument given is string A.



Output Format
Return the string A after reversing the string word by word.



Example Input
Input 1:
    A = "the sky is blue"
Input 2:
    A = "this is ib"


Example Output
Output 1:
    "blue is sky the"
Output 2:
    "ib is this"
*/

string Solution::solve(string A) {
    vector<string> allStrings;
    int i=0;
    while(i!=A.length() && A[i]==' ')
        i++;
    if(i==A.length())
        return "";
    while(i!=A.length()){
        string temp;
        while(i!=A.length() && A[i]!=' '){
            temp+=A[i];
            i++;            
        }
        //cout<<"yo:"<<temp<<endl;
        if(temp.length()!=0)
            allStrings.push_back(temp);
        while(i!=A.length() && A[i]==' '){
            i++;
        }
    }
    string res;
    for(int i=allStrings.size()-1;i>=0;i--){
        if(i!=0)
            res+=allStrings[i]+" ";
        else
            res+=allStrings[i];
    }
    return res;
}
