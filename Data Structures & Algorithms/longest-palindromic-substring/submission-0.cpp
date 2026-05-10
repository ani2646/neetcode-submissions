class Solution {
public:

    bool solve(string &s, int i, int j) {

        if (i >= j) {
            return true;
        }

        if (s[i] != s[j]) {
            return false;
        }

        return solve(s, i + 1, j - 1);
    }

    string longestPalindrome(string s) {

        int n = s.size();

        int maxLen = 0;
        int start = 0;

        for (int i = 0; i < n; i++) {

            for (int j = i; j < n; j++) {

                if (solve(s, i, j)) {

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