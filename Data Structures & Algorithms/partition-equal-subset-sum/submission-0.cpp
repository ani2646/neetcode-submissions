class Solution {
public:

    bool solve(vector<int>& nums, int sum, int i) {

        if(sum == 0) {
            return true;
        }

        if(i >= nums.size() || sum < 0) {
            return false;
        }

        // take OR not take
        return solve(nums, sum - nums[i], i + 1) ||
               solve(nums, sum, i + 1);
    }

    bool canPartition(vector<int>& nums) {

        int sum = 0;

        for(auto &x : nums) {
            sum += x;
        }

        // odd sum cannot be divided equally
        if(sum % 2 != 0) {
            return false;
        }

        return solve(nums, sum / 2, 0);
    }
};