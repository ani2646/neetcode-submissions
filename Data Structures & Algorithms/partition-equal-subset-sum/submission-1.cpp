class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int sum = 0;

        for(auto x : nums) {
            sum += x;
        }

        // odd sum cannot be divided equally
        if(sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;

        vector<bool> dp(target + 1, false);

        dp[0] = true;

        for(int i = 0; i < nums.size(); i++) {

            // go backwards
            for(int s = target; s >= nums[i]; s--) {

                dp[s] = dp[s] || dp[s - nums[i]];
            }
        }

        return dp[target];
    }
};