class Solution {
public:
    int solve(vector<int>& value,int i,vector<int>& dp){
        if(i>=value.size()){
            return 0;
        }
        if(dp[i]!=INT_MIN){
            return dp[i];
        }
        int result = INT_MIN;
        result = max(result,value[i] - solve(value,i+1,dp));
        if(i+1<value.size())
        {result = max(result,(value[i]+value[i+1]) - solve(value,i+2,dp));}
        if(i+1<value.size()&& i+2<value.size())
        {result = max(result,(value[i]+value[i+1]+value[i+2]) - solve(value,i+3,dp));}
        return dp[i] = result;

    }

    string stoneGameIII(vector<int>& stoneValue) {
        vector<int>dp(stoneValue.size()+1,INT_MIN);
        solve(stoneValue,0,dp);
        int ans = dp[0];
        if(ans>0){
            return "Alice";
        }
        else if(ans<0){
            return "Bob";
        }
        else{
            return "Tie";
        }
    }
};