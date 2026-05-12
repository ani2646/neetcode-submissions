class Solution {
public:
    int solve(string s, vector<string>& worddict, vector<int>& dp, int i) {

        if(i == s.size()) {
            return 1;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        for(int z = i; z < s.size(); z++) {

            if(find(worddict.begin(), worddict.end(),
                    s.substr(i, z - i + 1)) != worddict.end()) {

                dp[i] = solve(s, worddict, dp, z + 1);

                if(dp[i] == 1) {
                    return 1;
                }
            }
        }

        return dp[i] = 0;
    }

    bool wordBreak(string s, vector<string>& worddict) {

        int n = s.size();

        vector<int> dp(n, -1);

        return solve(s, worddict, dp, 0);
    }
};