class Solution {
public:
   int solve(vector<int>& nums,vector<int>& dp,int start,int n ){
        
        if(n<start){
           return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }

        return dp[n]=max(nums[n]+solve(nums,dp,start,n-2),solve(nums,dp,start,n-1));


    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
      vector<int>dp(n+1,-1);
      vector<int>dp1(n+1,-1);
     return max(solve(nums,dp,0,n-2),solve(nums,dp1,1,n-1));

    }
};
