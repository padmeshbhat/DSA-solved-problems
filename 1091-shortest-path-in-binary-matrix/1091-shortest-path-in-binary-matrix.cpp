class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>>q;
       

        if (grid[0][0] ==1){
            return -1;
        }
        if(grid[n-1][m-1]==1){
            return -1;
        }

        vis[0][0] = true;
        q.push({{0,0},1});
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int dist=q.front().second;
            q.pop();
            if(i == n-1 && j == m-1)
                return dist;

            int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
            int dc[] = {-1,  0,  1, -1, 1, -1, 0, 1};

            for(int k = 0; k < 8; k++)
            {
                int nr = i + dr[k];
                int nc = j + dc[k];

                if(nr >= 0 && nr < n &&
                 nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc]==0) {
                    vis[nr][nc]=true;
                    q.push({{nr,nc},dist+1});
        
                }
            }
        }
        return -1;

    }
};