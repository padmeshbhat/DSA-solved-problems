class Solution {
public:
    vector<vector<int>>ans;
    void solve(int start,vector<int>&curr,int n,int k){
        if(curr.size()==k){
            ans.push_back(curr);
        }
        for(int i=start;i<=n;i++){
            curr.push_back(i);
            solve(i+1,curr,n,k);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>curr;
        solve(1,curr,n,k);
        return ans;
        
    }
};