class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& mp) {
        // Base case
        if (node == NULL) return NULL;

        // If already cloned, return it
        if (mp.find(node) != mp.end()) {
            return mp[node];
        }

        // Create clone
        Node* clone = new Node(node->val);
        mp[node] = clone;

        // Clone neighbors
        for (auto nei : node->neighbors) {
            clone->neighbors.push_back(dfs(nei, mp));
        }

        return clone;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp;
        return dfs(node, mp);
    }
};