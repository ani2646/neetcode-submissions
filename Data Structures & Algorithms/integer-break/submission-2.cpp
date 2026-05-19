class Solution {
public:
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
        dp[0]=0;
        dp[1]=0;
        for(int i = 2;i<=n;i++){
            int fans = 0;
            for(int j = i-1;j>0;j--){
               int ans =  max(j*(i-j),j*dp[i-j]);
                fans = max(ans,fans);
            }
            dp[i] = fans;
        }
        return dp[n];
        
    }
};