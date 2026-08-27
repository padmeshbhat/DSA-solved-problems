class Solution {
public:
    vector<int>nums;
    int threshold;
    bool check(int k){
        int sum=0;
        
        for(auto ele:nums){
            sum+=(ele+k-1)/k;
        }
        return sum <=threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        this->nums=nums;
        this->threshold=threshold;
        int lo=1;
        int hi=*max_element(nums.begin(),nums.end());
        int ans=-1;
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