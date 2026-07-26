class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(10001,1e9);
        dp[0]=0;
        if(amount==0){
            return 0;
        }
        for(int i=1;i<dp.size();i++){
            for(auto coin:coins){
                if(i-coin<0) continue;
            dp[i] = min(dp[i],1+dp[i-coin]);
        }
        }
        return (dp[amount] == 1e9) ? -1 : dp[amount];




        
        
    }
};
