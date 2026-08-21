class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        int n = s.size();
        int i =0;
        vector<int>ans;
        for(int i = n-1;i>=0;i--){
            mp[s[i]] = max(mp[s[i]],i);

        }
        
       while(i<n){
            int final = mp[s[i]];
            for(int j = i+1;j<=final;j++){
                if(mp[s[j]]>final){
                    final = mp[s[j]];
                    continue;
                }
            }
            ans.push_back(final-i+1);
            i = final+1;
        }
        return ans;

        
        
    }
};
