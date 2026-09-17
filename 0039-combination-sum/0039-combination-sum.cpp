class Solution {
public:
    vector<vector<int>>ans;
    void solve(int start,int sum,int target,vector<int>&curr,vector<int>&candidates){
        if(sum==target){
            ans.push_back(curr);
            return;
        }
        if (sum>target){
            return;
        }
        for(int i=start;i<candidates.size();i++){
            curr.push_back(candidates[i]);
            sum+=candidates[i];
            solve(i,sum,target,curr,candidates);
            sum-=candidates[i];
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curr;
        solve(0,0,target,curr,candidates);
        return ans;
        
    }
};