class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        // head and tail
        int tail = 0, head = -1;

        // datastructure for the window
	    long long prod = 1;
        int n=nums.size();
	
        // answer maintain
        long long ans = 0;

        while (tail < n)
        {
            while (head+1<n && prod*nums[head+1]<k)
            {
                head++;
            
                // include elemenet at head in the data structure
                prod*=nums[head];
            }
       
        
        // update the answer for current start
            if(head>=tail){
                ans+=head-tail+1;
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
                prod /=nums[tail];
            
                tail++;
            }
        }
        return ans;
    }

    





        
    
};