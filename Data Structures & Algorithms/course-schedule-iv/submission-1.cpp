class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // vector<vector<int>>pre(numcourses);
        // for(auto it:prerequisites){
        //     pre[it[1]].push_back(it[0]);
        // };
        // vector<unordered_set<int>>final;
        // for(int i =0;i<pre;i++){
        //     for(auto x:pre[i]){
        //         final[i].push_back(x);
        //         for(auto t :pre[x]){
        //             final[i].push_back(pre[t]);
        //         }
        //     }
        // }
 vector<vector<int>> adj(numCourses);
vector<bool> ans;
queue<int> q;



vector<int> inorder(numCourses, 0);

for (auto p : prerequisites) {
    adj[p[0]].push_back(p[1]);
    inorder[p[1]]++;
}

// push 0 indegree
for (int i = 0; i < numCourses; i++) {
    if (inorder[i] == 0) {
        q.push(i);
    }
}
vector<unordered_set<int>>allpre(numCourses);
while(!q.empty()){
    auto it = q.front();
    q.pop();
    for(auto i: adj[it]){
        inorder[i]--;
        if(inorder[i]==0){
            q.push(i);
        }
        allpre[i].insert(it);
            for (auto x : allpre[it])
            allpre[i].insert(x);
    }
}
for(auto z:queries){
    ans.push_back(allpre[z[1]].count(z[0]));
}
return ans;

        
    
    
    
    }
};