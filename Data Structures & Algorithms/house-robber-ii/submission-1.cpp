class Solution {
public:

    int solve(vector<int>& nums, int start, int end) {

        vector<int> dp(nums.size(), 0);

        dp[start] = nums[start];

        for (int i = start + 1; i <= end; i++) {

            int take = nums[i];

            if (i - 2 >= start) {
                take += dp[i - 2];
            }

            int skip = dp[i - 1];

            dp[i] = max(take, skip);
        }

        return dp[end];
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        int case1 = solve(nums, 0, n - 2);

        int case2 = solve(nums, 1, n - 1);

        return max(case1, case2);
    }
};