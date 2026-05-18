class Solution {
public:
    int solve(vector<int>& coins, int amount,vector<int>& dp) {

    if(amount == 0) {
        return 0;
    }

    if(amount < 0) {
        return 1e9;
    }
    if(dp[amount]!=-2){
        return dp[amount];
    }

    int ans = 1e9;

    for(auto coin : coins) {

        ans = min(ans, 1 + solve(coins, amount - coin,dp));

    }

    return dp[amount] = ans;
}
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(10001,-2);
        solve(coins,amount,dp);
        int ans = dp[amount];

if(ans >= 1e9) {
    return -1;
}
if(ans ==-2){
    return 0;
}

return ans;
        
    }
};
