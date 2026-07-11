class Solution {
public:
    void solve(vector<int>& nums, vector<bool>& used, vector<int>& sub,vector<vector<int>>& ans){
        if(sub.size()==nums.size()){
            ans.push_back(sub);
            return;
        }

        for(int i = 0;i<used.size();i++){
            if(!used[i]){
                
                sub.push_back(nums[i]);
                used[i]=true;
                solve(nums,used,sub,ans);
                
                sub.pop_back();
                used[i]=false;
                
            }
        }


    }
    vector<vector<int>> permute(vector<int>& nums) {
          
            
             vector<vector<int>>ans;
            
              vector<bool> used(nums.size(), false);
               vector<int>sub;
              

             solve(nums,used,sub,ans);
             return ans;

    }  
};
