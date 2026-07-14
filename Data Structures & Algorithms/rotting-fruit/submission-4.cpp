class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int r  = grid.size();
        int c = grid[0].size();
        queue<pair<int,int>>q;
        for(int i =0;i<r;i++){
            for(int j = 0;j<c;j++){
                if(grid[i][j]==1){
                    fresh++;
                }
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        

        int time = 0;
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int s = q.size();
            for(int i =0;i<s;i++)
           { auto it = q.front();
            q.pop();
            for(auto dirs:dir){
                int ni = it.first+dirs[0];
                int nj = it.second+dirs[1];
                if(ni>=r||nj>=c||ni<0||nj<0||grid[ni][nj]==0) continue;
                else if(grid[ni][nj]==1){
                    grid[ni][nj]=2;
                    fresh--;
                 
                    q.push({ni,nj});
                }}
             }
             if(!q.empty()){
             time++;}
             
        }
        if(fresh>0){
            return -1;
        }
        return time;
       
        
        
    }
};
