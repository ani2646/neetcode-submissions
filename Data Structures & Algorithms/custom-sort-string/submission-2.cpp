class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        string ans;

        // Store position of each character in order
        for(int i = 0; i < order.size(); i++) {
            mp[order[i]] = i;
        }

        vector<int> temp;

        // Separate characters according to whether they are in order
        for(auto chr : s) {
            if(mp.count(chr)) {
                temp.push_back(mp[chr]);
            }
            else {
                ans += chr;
            }
        }

        // Sort according to their positions in order
        sort(temp.begin(), temp.end());

        // Convert positions back to characters
        for(auto it : temp) {
            ans += order[it];
        }

        return ans;
    }
};