class Solution {
public:
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        stack<int>st;
        for(auto e:edges){
            int v=e[0];
            int u=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        st.push(source);
        vis[source]=1;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(node==destination){
                return true;
            }
            for(auto v:adj[node]){
                if(vis[v]==0){
                    vis[v]=1;
                    st.push(v);
                }
            }
        }
        return false;
    }
};