class Solution {
public:
int solve(vector<int>& stones,int sum,int i,vector<vector<int>>& dp){
    if(sum==0){
        return 0;
    }
    if(i>=stones.size()){
        return sum;
    }
    if(dp[i][sum]!=-1){
        return dp[i][sum];
    }
    if(sum>=stones[i]){
    return dp[i][sum]=min(solve(stones,sum-stones[i],i+1,dp),solve(stones,sum,i+1,dp));}
    else{
        return dp[i][sum] = solve(stones,sum,i+1,dp);
    }
}
    int lastStoneWeightII(vector<int>& stones) {

        int totalsum = 0;
        for(auto i : stones){
            totalsum = totalsum + i;
        }
        int sum = totalsum/2;
        vector<vector<int>>dp(stones.size(),vector<int>(sum+1,-1));
        solve(stones,sum,0,dp);
        int leftover =  solve(stones,sum,0,dp);
        return totalsum-2*(sum-leftover);

        
    }
};