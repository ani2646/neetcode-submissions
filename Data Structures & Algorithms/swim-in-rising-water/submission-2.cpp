class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        vector<vector<int>>vis(n,vector<int>(n,0));
        dist[0][0] = grid[0][0];
        vector<vector<int>>dirs ={{1,0},{-1,0},{0,1},{0,-1}};
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.push({0,0,0});
        while(!pq.empty()){
            auto [wt,r,c] = pq.top();
            pq.pop();
            if(vis[r][c]) continue;
            vis[r][c]=1;
            if(r==n-1&&c==n-1){
                return wt;
            }
            for(auto dir:dirs){
                int rn = r+dir[0];
                int cn = c+dir[1];
                if(rn > n-1||rn<0||cn<0||cn>n-1||vis[rn][cn])continue;
                int newcost = max(dist[r][c],grid[rn][cn]);
                if(newcost<dist[rn][cn]){
                    dist[rn][cn] = newcost;
                    pq.push({newcost,rn,cn});
                }
            }
        }
        return dist[n-1][n-1];
        
    }
};
