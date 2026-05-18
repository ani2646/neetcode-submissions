class Solution {
public:


    int combinationSum4(vector<int>& nums, int target) {

        vector<int> dp(target + 1, -1);

       
        dp[0] = 1;
        for(int i = 1;i<=target;i++){
            int ans = 0;
            for(auto num:nums){
                if(i-num>=0)
                {ans = ans+dp[i-num];}
            }
            dp[i] = ans;
        }
        return dp[target];
    }
};