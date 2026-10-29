class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health){
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        vector<vector<int>> visited(n, vector<int>(m, 0));

        deque<pair<int, int>> dq;

        dist[0][0] = grid[0][0];
        dq.push_front({0, 0});

        while (!dq.empty()) {
            auto p = dq.front();
            dq.pop_front();

            int i = p.first;
            int j = p.second;

            if (visited[i][j] == 1) continue;

            visited[i][j] = 1;
            if (i - 1 >= 0) {
                int cost;

                if (grid[i - 1][j] == 1) {
                    cost = 1;
                } else {
                    cost = 0;
                }

                if (visited[i - 1][j] == 0 &&
                    dist[i - 1][j] > dist[i][j] + cost) {

                    dist[i - 1][j] = dist[i][j] + cost;

                    if (cost == 0) {
                        dq.push_front({i - 1, j});
                    } else {
                        dq.push_back({i - 1, j});
                    }
                }
            }

            // DOWN
            if (i + 1 < n) {
                int cost;

                if (grid[i + 1][j] == 1) {
                    cost = 1;
                } else {
                    cost = 0;
                }

                if (visited[i + 1][j] == 0 &&
                    dist[i + 1][j] > dist[i][j] + cost) {

                    dist[i + 1][j] = dist[i][j] + cost;

                    if (cost == 0) {
                        dq.push_front({i + 1, j});
                    } else {
                        dq.push_back({i + 1, j});
                    }
                }
            }

            // LEFT
            if (j - 1 >= 0) {
                int cost;

                if (grid[i][j - 1] == 1) {
                    cost = 1;
                } else {
                    cost = 0;
                }

                if (visited[i][j - 1] == 0 &&
                    dist[i][j - 1] > dist[i][j] + cost) {

                    dist[i][j - 1] = dist[i][j] + cost;

                    if (cost == 0) {
                        dq.push_front({i, j - 1});
                    } else {
                        dq.push_back({i, j - 1});
                    }
                }
            }

            // RIGHT
            if (j + 1 < m) {
                int cost;

                if (grid[i][j + 1] == 1) {
                    cost = 1;
                } else {
                    cost = 0;
                }

                if (visited[i][j + 1] == 0 &&
                    dist[i][j + 1] > dist[i][j] + cost) {

                    dist[i][j + 1] = dist[i][j] + cost;

                    if (cost == 0) {
                        dq.push_front({i, j + 1});
                    } else {
                        dq.push_back({i, j + 1});
                    }
                }
            }
        
        }
        if (dist[n - 1][m - 1] < health) {
            return true;
        } else {
            return false;
        }
    }

          
    
};