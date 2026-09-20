class Solution {
public:
    vector<vector<string>>ans;
    bool is_palindrome(int l,int r,string &s){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
               
            }
            l++;
            r--;
           
        }
        return true;
    }
   
    void solve(int start,string s,vector<string>&curr){
        if(start==s.size()){
            ans.push_back(curr);
            return ;
        }
        for(int i=start;i<s.size();i++){
            if (is_palindrome(start,i,s)){
                curr.push_back(s.substr(start,i-start+1));
                solve(i+1,s,curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>curr;
        solve(0,s,curr);
        return ans;
    }
};