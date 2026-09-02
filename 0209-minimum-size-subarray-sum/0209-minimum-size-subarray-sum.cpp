class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
          // head and tail
        int tail = 0, head = -1;

    // datastructure for the window
	    int sum = 0;
        int n=nums.size();
	
    // answer maintain
        int ans = INT_MAX;

        while (tail < n)
        {
            while (head+1<n && sum < target)
            {
                head++;
            
            // include elemenet at head in the data structure
                sum+=nums[head];
            
            }
       
        
            // update the answer for current start
            if(sum>=target){
                ans=min(ans,head-tail+1);
            }
        
        
            // move start one step forward.
            if (tail > head)    // keep it same for all question, it basically help to handle empty subarray
            {
                tail++;
                head = tail - 1;
            }
            else
            {
            // change data  structure because removing tail element
                sum-=nums[tail];
            
                tail++;
            }
        }
        if(ans==INT_MAX){
            return 0;
        }
        return ans;
    }    

   


   
};