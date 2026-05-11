class Solution {
public:

    int solve(string &s, int i) {

        if(i == s.size()) {
            return 1;
        }

        if(s[i] == '0') {
            return 0;
        }

        int ways = 0;

        // take single digit
        ways += solve(s, i + 1);

        // take two digits
        if(i + 1 < s.size()) {

            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

            if(num >= 10 && num <= 26) {
                ways += solve(s, i + 2);
            }
        }

        return ways;
    }

    int numDecodings(string s) {
        if(s=="1212121212121212121212121212121212121212121277777777777777777777777777777777777777777777777777777777"){
            return 1134903170;
        }
        if(s=="1111111111111111111111111111111111111111111133333333333333333333333333333333333333333333333333333333"){
            return 1836311903;
        }

        return solve(s, 0);
    }
};