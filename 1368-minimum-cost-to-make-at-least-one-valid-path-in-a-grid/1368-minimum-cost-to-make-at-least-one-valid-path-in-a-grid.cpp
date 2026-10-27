class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        vector<vector<int>> visited(n, vector<int>(m, 0));
        deque<pair<int,int>>dq;
        dist[0][0]=0;
        dq.push_front({0,0});
        while(!dq.empty()){
            auto p=dq.front();
            dq.pop_front();
            int i=p.first;
            int j=p.second;
            if(visited[i][j]==1)continue;
            visited[i][j]=1;
            if(i-1>=0){
                int cost;
                if(grid[i][j]==4){
                    cost=0;
                }
                else{
                    cost=1;
                }
                if(visited[i-1][j]==0 && dist[i-1][j]>dist[i][j]+cost){
                    dist[i-1][j]=dist[i][j]+cost;
                    if(cost==0){
                        dq.push_front({i-1,j});
                    }
                    else{
                        dq.push_back({i-1,j});
                    }
                }
            }

            if(i+1<n){
                int cost;
                if(grid[i][j]==3){
                    cost=0;
                }
                else{
                    cost=1;
                }
                if(visited[i+1][j]==0 && dist[i+1][j]>dist[i][j]+cost){
                    dist[i+1][j]=dist[i][j]+cost;
                    if(cost==0){
                        dq.push_front({i+1,j});
                    }
                    else{
                        dq.push_back({i+1,j});
                    }
                }
            }
            if(j-1>=0){
                int cost;
                if(grid[i][j]==2){
                    cost=0;
                }
                else{
                    cost=1;
                }
                if(visited[i][j-1]==0 && dist[i][j-1]>dist[i][j]+cost){
                    dist[i][j-1]=dist[i][j]+cost;
                    if(cost==0){
                        dq.push_front({i,j-1});
                    }
                    else{
                        dq.push_back({i,j-1});
                    }
                }
            }
            if(j+1<m){
                int cost;
                if(grid[i][j]==1){
                    cost=0;
                }
                else{
                    cost=1;
                }
                if(visited[i][j+1]==0 && dist[i][j+1]>dist[i][j]+cost){
                    dist[i][j+1]=dist[i][j]+cost;
                    if(cost==0){
                        dq.push_front({i,j+1});
                    }
                    else{
                        dq.push_back({i,j+1});
                    }
                }
            }

        }
        return dist[n-1][m-1];

    }
};