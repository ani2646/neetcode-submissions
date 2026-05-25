class Solution {
public:
    int solve(int i,int j,string t,string r,vector<vector<int>>& dp){
        if(i == t.size() || j == r.size())
        return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(t[i]==r[j]){
            return dp[i][j] =1 + solve(i+1,j+1,t,r,dp);

        }
        else{
            return dp[i][j] = max(solve(i+1,j,t,r,dp),solve(i,j+1,t,r,dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
            solve(0,0,text1,text2,dp);
            return dp[0][0];
        
    }
};
