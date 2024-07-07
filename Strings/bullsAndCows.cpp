/*
Problem Description
 
 

 You are playing the Bulls and Cows game with your friend.

You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

The number of "bulls", which are digits in the guess that are in the correct position.
The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. 
Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls. 
Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.



Problem Constraints
1 <= secret.length, guess.length <= 100000
secret.length == guess.length
secret and guess consist of digits only.


Input Format
First argument is string denoting secret string 


Second argument is string denoting guess string 



Output Format
Return the hint for you friend's guess.


Example Input
Input 1:
secret = "1807", guess = "7810"
Input 2:

secret = "1123", guess = "0111"


Example Output
Ouput 1:
"1A3B"
Ouput 2:

"1A1B"
*/

string Solution::solve(string A, string B) {
    int bulls = 0;
    int cows = 0;
    string ans;
    map<char,int> allAChars;
    map<char,int> allBChars;
    for(int i=0;i<A.length();i++){
        if(A[i]==B[i]){
            bulls++;
        }
        else{
            allAChars[A[i]]++;
            allBChars[B[i]]++;
        }
    }
    ans += to_string(bulls)+"A";
    map<char,int>::iterator it;
    for(it=allBChars.begin();it!=allBChars.end();it++){
        if(allAChars.find(it->first)!=allAChars.end()){
            //cout<<it->second<<" "<<allAChars.find(it->first)->second<<endl;
            cows += min(it->second,allAChars.find(it->first)->second);
        }
    }
    ans += to_string(cows)+"B";
    return ans;
    
}
