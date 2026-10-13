class Solution {
public:
    int dfs(int r,int c, vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(r<0 || r>=n || c<0|| c>=m || grid[r][c]==0){
            return 0;
        }
        int cnt=1;
        grid[r][c]=0;

        cnt += dfs(r-1,c,grid);  
        cnt += dfs(r+1,c,grid);  
        cnt += dfs(r,c-1,grid);  
        cnt += dfs(r,c+1,grid);  

        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int area=dfs(i,j,grid);
                    ans=max(ans,area);
                }
            }
        }
        return ans;
    }
};