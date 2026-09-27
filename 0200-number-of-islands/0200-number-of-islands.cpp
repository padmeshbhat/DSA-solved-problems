class Solution {
public:

    void bfs(int row, int col, vector<vector<int>> &visited,
             vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // Mark starting cell as visited
        visited[row][col] = 1;

        queue<pair<int,int>> q;
        q.push({row,col});

        while(!q.empty()) {

            row = q.front().first;
            col = q.front().second;
            q.pop();

            // 4 directions
            int drow[] = {-1, 1, 0, 0};
            int dcol[] = {0, 0, -1, 1};

            for(int k = 0; k < 4; k++) {

                int nr = row + drow[k];
                int nc = col + dcol[k];

                // Inside grid + land + not visited
                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < m &&
                   grid[nr][nc] == '1' &&
                   !visited[nr][nc]) {

                    visited[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int island = 0;

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {

                // New unvisited land = new island
                if(grid[row][col] == '1' && !visited[row][col]) {

                    island++;

                    bfs(row, col, visited, grid);
                }
            }
        }

        return island;
    }
};