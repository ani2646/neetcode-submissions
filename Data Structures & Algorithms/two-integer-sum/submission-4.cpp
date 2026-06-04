class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>hash;
        vector<int> ans(2);
        for (int i = 0 ;i<nums.size();i++){
            auto it = hash.find(target-nums[i]);
            if(it!=hash.end()){
                ans[0] = hash[target-nums[i]];
                ans[1] = i;
            }
            else{
                hash[nums[i]] = i;
            }
       
    }
   
    return ans;
    
    
    
    }
};
