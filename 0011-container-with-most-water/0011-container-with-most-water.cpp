class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans =0;
        int st=0;
        int n= height.size();
        int end=n-1;
        while(st<end){
            int area=min(height[st],height[end])*(end-st);
            ans=max(ans,area);
            if(height[end]>height[st]){
                st++;
            }
            else{
                end--;
            }
        }
        return ans;
    }
};