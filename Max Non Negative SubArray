vector<int> Solution::maxset(vector<int> &A) {
    long long int max_sum = INT_MIN;
    long long int curr_sum = 0;
    long long int max_idx;
    vector<vector<int> >positives;
    vector<int> temp;
    for(int i=0;i<A.size();i++){
        if(A[i]<0){
            positives.push_back(temp);
            temp.clear();
            if(curr_sum > max_sum){
                max_sum = curr_sum;
                max_idx = positives.size()-1;
            }
            curr_sum = 0;
            continue; 
        }
        else{
            curr_sum += A[i];
            temp.push_back(A[i]);
        }
        
        if(i==A.size()-1){
            positives.push_back(temp);
            if(curr_sum > max_sum){
                max_sum = curr_sum;
                max_idx = positives.size()-1;
            }
        } 
    }
    return positives[max_idx];
}
