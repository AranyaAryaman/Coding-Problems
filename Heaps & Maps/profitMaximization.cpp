/*
Profit Maximisation
Programming
Heaps And Maps
easy
78.7% Success

140

4

Bookmark
Asked In:
Problem Description
 
 

 Given an array A , representing seats in each row of a stadium. You need to sell tickets to B people.

Each seat costs equal to the number of vacant seats in the row it belongs to. The task is to maximize the profit by selling the tickets to B people.



Problem Constraints
1 <= |A| <= 100000

1 <= B <= 1000000



Input Format
First argument is the array A.

Second argument is integer B.



Output Format
Return one integer, the answer to the problem.



Example Input
Input 1:

A = [2, 3]
B = 3
Input 2:

A = [1, 4]
B = 2


Example Output
Output 1:

7
Output 2:

7


Example Explanation
Explanation 1:

 First you serve the seat with number = 3. Then with 2 and then with 2. hence answer = 3 + 2 + 2 = 7.
Explanation 2:

 You give both tickets from the row with 4 seats. 4 + 3 = 7.
*/

int parent(int i){
    return (i-1)/2;
}

int left(int i){
    return 2*i+1;
}

int right(int i){
    return 2*i+2;
}

void maxHeapify(vector<int>& A, int i){
    int largest = i;
    if(left(i)<=A.size()-1 && A[left(i)]>A[i])
        largest = left(i);
    if(right(i)<=A.size()-1 && A[right(i)]>A[largest])
        largest = right(i);
    if(largest!=i){
        swap(A[largest],A[i]);
        maxHeapify(A,largest);
    }
        
}

void buildMaxHeap(vector<int> &A){
    for(int i=A.size()/2;i>=0;i--){
        maxHeapify(A,i);
    }
}
 
int extractMax(vector<int> &A){
    return A[0];
}

void decreaseKeyByOne(vector<int> &A){
    A[0]--;
    maxHeapify(A,0);
}

int Solution::solve(vector<int> &A, int B) {
    buildMaxHeap(A);
    // for(int i=0;i<A.size();i++)
    //     cout<<A[i]<<" ";
    int total_cost = 0;
    for(int i=0;i<B;i++){
        total_cost += extractMax(A);
        decreaseKeyByOne(A);
    }
    return total_cost;
}
