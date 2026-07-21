class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> s(wordList.begin(), wordList.end());

        if (!s.count(endWord))
            return 0;

        queue<pair<int, string>> q;
        q.push({1, beginWord});

        // Mark beginWord as visited if it exists in the set
        s.erase(beginWord);

        while (!q.empty()) {

            auto [level, curr] = q.front();
            q.pop();

            for (int j = 0; j < curr.size(); j++) {

                char original = curr[j];

                for (char c = 'a'; c <= 'z'; c++) {

                    curr[j] = c;

                    if (curr == endWord)
                        return level + 1;

                    if (s.count(curr)) {

                        q.push({level + 1, curr});
                        s.erase(curr);   // Mark as visited

                    }
                }

                curr[j] = original; // Restore original character
            }
        }

        return 0;
    }
};