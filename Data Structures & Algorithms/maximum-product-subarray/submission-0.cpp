class Solution {
public:

    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(2,INT_MAX));
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        for(int i = 1 ;i<n;i++){
            dp[i][0] = max({nums[i],dp[i-1][0]*nums[i],dp[i-1][1]*nums[i]});
            dp[i][1]= min({nums[i],dp[i-1][0]*nums[i],dp[i-1][1]*nums[i]});
        }
       
        int ans = dp[0][0];
        for(int i = 0 ;i<n;i++){
            ans = max(dp[i][0],ans);
        }
        return ans;

        
    }
};
