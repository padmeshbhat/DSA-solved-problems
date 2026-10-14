class Solution {
public:
    void dfs(vector<vector<int>>& rooms,int node,vector<int> &vis){
        vis[node]=1;
        for(auto v:rooms[node]){
            if(vis[v]==0){
                dfs(rooms,v,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>vis(n,0);
        dfs(rooms,0,vis);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                return false;
            }
        }
        return true;
    }
    
};