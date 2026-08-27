class Solution {
public:
    vector <int>piles;
    int h;
    bool check(int k){
        long long hours=0;
        for(int i=0;i<piles.size();i++){
            hours+=(piles[i]+k-1)/k;
        }
        return hours<=h;

    }
   
    


    int minEatingSpeed(vector<int>& piles, int h) {
        this->piles=piles;
        this->h=h;
        
        int ans=-1;
        int lo=1;
        int hi=*max_element(piles.begin(),piles.end());
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