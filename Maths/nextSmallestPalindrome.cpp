/*
Problem Description

Given a numeric string A representing a large number you need to find the next smallest palindrome greater than this number.



Problem Constraints
1 <= |A| <= 100

A doesn't start with zeroes and always contain digits from 0-9.



Input Format
First and only argument is an string A.



Output Format
Return a numeric string denoting the next smallest palindrome greater than A.
*/

string Solution::solve(string A) {
    int size = A.size();
    int mid = (size+1)/2;

    bool incr = true;
    // check if we need to add 1 to first half of the number
    // before making it into a palindrome.
    for(int i = mid; i < size; i++) {
        if(A[size-1-i] == A[i]) continue;
        if(A[size-1-i] < A[i]) incr = true;
        if(A[size-1-i] > A[i]) incr = false;
        break;
    }

    A = A.substr(0,mid);

    //add 1 to the first half of the number.
    if(incr) {
        int carry = 1;

        for(int i = mid-1; i >= 0 && carry == 1; i--)
            A[i] = ( A[i] == '9' ? '0' : A[i] + carry--);

        if(carry) //every digit must have been '9'
            return '1' + string(size-1,'0') + '1';
    }

    //append the first half reversed to make the palindrome.
    for(int i = size-A.size()-1; i >= 0; i--)
        A.push_back(A[i]);

    return A;
}
