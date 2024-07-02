/*
Problem Description
 
 

Given an integer A, return the number of trailing zeroes in A!.

Note: Your solution should be in logarithmic time complexity.



Problem Constraints
0 <= A <= 10000000



Input Format
First and only argumment is integer A.



Output Format
Return an integer, the answer to the problem.



Example Input
Input 1:

 A = 4
Input 2:

 A = 5


Example Output
Output 1:

 0
Output 2:

 1
*/

int findFives(int A){
    int numFives = 0;
    while(A%5==0){
        numFives++;
        A=A/5;
        if(A%5!=0)
            break;
    }
    return numFives;
}

int findTwos(int A){
    int numTwos = 0;
    while(A%2==0){
        numTwos++;
        A=A/2;
        if(A%2!=0)
            break;
    }
    return numTwos;
}

int Solution::trailingZeroes(int A) {
    int numTwos = 0;
    int numFives = 0;
    for(int i=1;i<=A;i++){
        numTwos += findTwos(i);
        // if(numTwos>0) cout<<i<<" "<<numTwos<<endl;
        numFives += findFives(i);
        // if(numTwos>0) cout<<i<<" "<<numFives<<endl;
    }
    return min(numTwos,numFives);
}
