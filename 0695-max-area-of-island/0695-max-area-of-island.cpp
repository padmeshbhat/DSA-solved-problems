class Solution {
public:
   
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;

        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    vis[i][j]=true;
                    q.push({i,j});
                    int area=0;
                    while(!q.empty()){
                        int i=q.front().first;
                        int j=q.front().second;
                        q.pop();

                        area++;
                        if(i-1>=0&& !vis[i-1][j]&&grid[i-1][j]==1){
                            q.push({i-1,j});
                            vis[i-1][j]=true;
                        }

                        if(i+1<n&& !vis[i+1][j]&&grid[i+1][j]==1){
                            q.push({i+1,j});
                            vis[i+1][j]=true;
                         }

                        if(j-1>=0&& !vis[i][j-1]&&grid[i][j-1]==1){
                            q.push({i,j-1});
                            vis[i][j-1]=true;
                         }
 
                        if(j+1<m&& !vis[i][j+1]&&grid[i][j+1]==1){
                            q.push({i,j+1});
                            vis[i][j+1]=true;
                         }
                    }
                    ans=max(ans,area);
        

                }
            }
        }
        return ans;
        

    }
};