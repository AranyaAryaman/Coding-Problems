bool comp(pair<int,int> p1, pair<int,int> p2){
    return p1.second < p2.second;
}

int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int m = A.size();
    int n = B.size();
    vector<pair<int,int>> v1;
    for(int i=0;i<A.size();i++){
        v1.push_back(make_pair(A[i],B[i]));
    } 
    sort(v1.begin(),v1.end(),comp);
    for(int i=0;i<v1.size();i++){
        A[i]=v1[i].first;
        B[i]=v1[i].second;
    }
    
    // for(int i=0;i<A.size();i++){
    //     cout<<A[i]<<" "<<B[i]<<endl;
    // }
    vector<vector<int>>dp(m+1,vector<int>(C+1,0));
    //int dp[m+1][C+1];
    for(int i=1;i<=m;i++){
        for(int j=C;j>=0;j--){
            if(j<B[i-1])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],A[i-1]+dp[i-1][j-B[i-1]]);
        }
    }
    // for(int i=0;i<=m;i++){
    //     for(int j=0;j<=C;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return dp[m][C];
}
