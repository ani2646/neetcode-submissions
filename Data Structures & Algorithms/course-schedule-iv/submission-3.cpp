class Solution {
public:
    bool dfs(int course, int target,
             vector<vector<int>>& adj,
             vector<bool>& vis) {

        if (course == target)
            return true;

        vis[course] = true;

        for (int nxt : adj[course]) {
            if (!vis[nxt] && dfs(nxt, target, adj, vis))
                return true;
        }

        return false;
    }

    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {

        vector<vector<int>> adj(numCourses);

        // prerequisite -> course
        for (auto &p : prerequisites) {
            adj[p[0]].push_back(p[1]);
        }

        vector<bool> ans;

        for (auto &q : queries) {
            int u = q[0];
            int v = q[1];

            vector<bool> vis(numCourses, false);

            // A course is not considered a prerequisite of itself
            if (u == v) {
                ans.push_back(false);
                continue;
            }

            ans.push_back(dfs(u, v, adj, vis));
        }

        return ans;
    }
};
//  vector<vector<int>> adj(numCourses);
// vector<bool> ans;
// queue<int> q;



// vector<int> inorder(numCourses, 0);

// for (auto p : prerequisites) {
//     adj[p[0]].push_back(p[1]);
//     inorder[p[1]]++;
// }

// // push 0 indegree
// for (int i = 0; i < numCourses; i++) {
//     if (inorder[i] == 0) {
//         q.push(i);
//     }
// }
// vector<unordered_set<int>>allpre(numCourses);
// while(!q.empty()){
//     auto it = q.front();
//     q.pop();
//     for(auto i: adj[it]){
//         inorder[i]--;
//         if(inorder[i]==0){
//             q.push(i);
//         }
//         allpre[i].insert(it);
//             for (auto x : allpre[it])
//             allpre[i].insert(x);
//     }
// }
// for(auto z:queries){
//     ans.push_back(allpre[z[1]].count(z[0]));
// }
// return ans;

        
    
    
    
