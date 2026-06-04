class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>ans(2*nums.size());
        for(int i = 0;i<2*nums.size();i++ ){
           /* if (i<nums.size()){
                ans[i]=nums[i];

            
            } 
            else{
                ans[i]=nums[i-nums.size()];
            }*/
            ans[i]= nums[(i%nums.size())] ;
                  }
                  return ans;
        
    }
};