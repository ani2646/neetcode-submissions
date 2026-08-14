class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int initial = 0;

        for (auto x : nums) {
            if (x == k) {
                initial++;
            }
        }

        int ans = initial;

        for (int i = 1; i <= 50; i++) {
            int sum = 0;
            int maxi = 0;
              if (i == k) {
                continue;
            }

            for (int j = 0; j < nums.size(); j++) {

                if (nums[j] == i) {
                    sum += 1;
                }
                else if (nums[j] == k) {
                    sum -= 1;
                }

                sum = max(sum, 0);
                maxi = max(maxi, sum);
            }

            ans = max(ans, initial + maxi);
        }

        return ans;
    }
};