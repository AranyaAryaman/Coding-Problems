/*
Problem Description
 
 

Another question which belongs to the category of questions which are intentionally stated vaguely.

Expectation is that you will ask for correct clarification or you will state your assumptions before you start coding.

Implement strStr().

strstr - locate a substring ( needle ) in a string ( haystack ).

Try not to use standard library string functions for this question.

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

NOTE: String A is haystack, B is needle.

Good clarification questions:

What should be the return value if the needle is empty?
What if both haystack and needle are empty?
For the purpose of this problem, assume that the return value should be -1 in both cases.


Problem Constraints
1 <= |haystack| <= 104
1 <= |needle| <= 103


Input Format
The first argument is a string A (haystack)
The second argument is a string B (needle)


Output Format
Return an integer, the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

int Solution::strStr(const string A, const string B) {
    if(A==B)    return 0;
    if(B.length() > A.length()||A.length()==0||B.length()==0) return -1;
    for(int i=0;i<A.length();i++){
        int ind = i;
        if(A[i]==B[0]){
            int j=0;
            while(j<B.length()&&i<A.length()&&A[i]==B[j]){
                i++;
                j++;
            }
            if(j==B.length()&&i<=A.length())
                return ind;
        }
        i=ind;
    }
    return -1;
}
