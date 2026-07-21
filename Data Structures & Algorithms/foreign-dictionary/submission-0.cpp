class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, int> indegree;
        unordered_map<char, vector<char>> adj;

        // Add every unique character as a node
        for (auto &word : words) {
            for (char ch : word) {
                adj[ch];
            }
        }

        int n = words.size();

        // Build the graph
        for (int i = 0; i < n - 1; i++) {
            string first = words[i];
            string second = words[i + 1];

            int j = 0;
            while (j < min(first.size(), second.size())) {
                if (first[j] != second[j]) {

                    // Avoid duplicate edges
                    bool found = false;
                    for (char x : adj[first[j]]) {
                        if (x == second[j]) {
                            found = true;
                            break;
                        }
                    }

                    if (!found)
                        adj[first[j]].push_back(second[j]);

                    break;
                }
                j++;
            }

            // Invalid prefix case
            if (j == min(first.size(), second.size()) &&
                first.size() > second.size()) {
                return "";
            }
        }

        // Compute indegrees
        for (auto &p : adj) {
            for (char neigh : p.second) {
                indegree[neigh]++;
            }
        }

        queue<char> q;

        // Push all nodes with indegree 0
        for (auto &p : adj) {
            if (indegree[p.first] == 0) {
                q.push(p.first);
            }
        }

        string ans;

        // Kahn's Algorithm
        while (!q.empty()) {
            char curr = q.front();
            q.pop();

            ans.push_back(curr);

            for (char neigh : adj[curr]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        // Cycle check
        if (ans.size() != adj.size())
            return "";

        return ans;
    }
};