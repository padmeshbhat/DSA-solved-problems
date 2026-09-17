class Solution {
public:
    vector<vector<int>>ans; 
    void solve(int sum,int start,int target,vector<int>&candidates,vector<int>&curr){
        if(sum==target){
            ans.push_back(curr);
            return;
        }
        if(sum>target){
            return;
        }
        for(int i=start;i<candidates.size();i++){
            if(i > start && candidates[i] == candidates[i-1])
                continue;

            curr.push_back(candidates[i]);
            sum+=candidates[i];
            solve(sum,i+1,target,candidates,curr);
            sum-=candidates[i];
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>curr;
        sort(candidates.begin(),candidates.end());
        solve(0,0,target,candidates,curr);
        return ans;
    }
};