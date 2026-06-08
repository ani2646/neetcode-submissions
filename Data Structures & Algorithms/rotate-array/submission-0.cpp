class Solution {
public:
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n; // handle k > n
    
    reverse(nums.begin(), nums.end());         // whole
    reverse(nums.begin(), nums.begin() + k);   // first k
    reverse(nums.begin() + k, nums.end());     // rest
}

};