class Solution {
public:
    int solve(int n,vector<int>& dp){
        if(n <=1){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int fans= 0;
        for(int i =n-1;i>0;i--){
         int ans = max(i*(n-i),i*solve(n-i,dp));
         
         fans= max(ans,fans);
    
        }
        return dp[n] = fans;
        }
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
         solve(n,dp);
         return dp[n];
       
        
    }
};