/*
Problem Description
 
 

A hotel manager has to process N advance bookings of rooms for the next season. His hotel has C rooms. Bookings contain an arrival date and a departure date. He wants to find out whether there are enough rooms in the hotel to satisfy the demand. Write a program that solves this problem in time O(N log N) .

Note- If we have arrival and departure on the same date then arrival must be served before the departure.


Problem Constraints
1 <= |A| <= 106
|A|== |B|
1 <= Ai <= Bi <= 108
1 <= C <= 106



Input Format
First argument is an integer array A containing arrival time of booking.

Second argument is an integer array B containing departure time of booking.

Third argument is an integer C denoting the count of rooms.



Output Format
Return True if there are enough rooms for N bookings else return False.

Return 0/1 for C programs.
*/

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    if(K==0 & arrive.size()!=0)    return 0;
    if(arrive.size()<=K)    return 1;
    vector<pair<int,int>> bookings;
    for(int i=0;i<arrive.size();i++){
        bookings.push_back({arrive[i],0});
        bookings.push_back({depart[i],1});
    }
    sort(bookings.begin(),bookings.end());
    int count = 0, glomax = 0;
    for(int i=0;i<bookings.size();i++){
        if(bookings[i].second == 0){
            count++;
            glomax = max(glomax,count);
        }
        else{
            count--;
        }
    }
    if(glomax > K)
        return 0;
    return 1;
}
