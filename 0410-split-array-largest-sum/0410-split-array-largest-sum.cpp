class Solution {
public:
    vector<int> nums;
    int n,k;
    bool check(int x){
        int sum=0;
        int part=1;
        for(int y:nums){
            if(sum+y<=x){
                sum+=y;
            }
            else{
                part++;
                sum=y;
            }
        }
        return part<=k;
    }
   

    int splitArray(vector<int>& nums, int k) {
        this->nums = nums;
        this->k = k;
        n=nums.size();
        int lo=*max_element(nums.begin(),nums.end());
        int hi=0;
        int ans=-1;
        for(int x:nums){
            hi+=x;
        }
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(mid)){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
        
    }
};