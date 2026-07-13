class Solution {
public:
    bool f(unordered_map<char, int>& mp, string a, string b) {
        int i = 0;

        while (i < a.size() && i < b.size()) {
            if (mp[a[i]] < mp[b[i]]) {
                return true;
            }
            if (mp[a[i]] > mp[b[i]]) {
                return false;
            }
            i++;
        }

        // All common characters were equal.
        // Then the shorter word should come first.
        return a.size() <= b.size();
    }

    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;

        for (int i = 0; i < order.size(); i++) {
            mp[order[i]] = i;
        }

        for (int i = 0; i < words.size() - 1; i++) {
            if (!f(mp, words[i], words[i + 1])) {
                return false;
            }
        }

        return true;
    }
};