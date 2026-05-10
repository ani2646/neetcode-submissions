class Solution {
public:

    int solve(string &s, int i, int j,vector<vector<int>>& dp) {

        if (i >= j) {
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if (s[i] != s[j]) {
            return dp[i][j]=0;
            
        }

        return dp[i][j] = solve(s, i + 1, j - 1,dp);
    }

    string longestPalindrome(string s) {

        int n = s.size();

        int maxLen = 1;
        int start = 0;

        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++) {

            for (int j = i; j < n; j++) {

                if (solve(s, i, j,dp)==1) {

                    int len = j - i + 1;

                    if (len > maxLen) {
                        maxLen = len;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};