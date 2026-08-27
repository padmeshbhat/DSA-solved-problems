class Solution {
public:
    int m,n,k;
    bool check(int x){
        int count=0;
        for(int i=1;i<=m;i++){
            count+=min(n,x/i);
        }
        return count>=k;
    }
    int findKthNumber(int m, int n, int k) {
        this->m=m;
        this->n=n;
        this->k=k;
        int lo=1;
        int hi=m*n;
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