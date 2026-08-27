class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int tail = 0, head = -1;
        int n=nums.size();

        // datastructure for the window
	    int cnt = 0;
	
        // answer maintain
        int ans = 0;

        while (tail < n)
        {
            while (head+1<n && cnt<k)
            {
                head++;
            
                // include elemenet at head in the data structure
                if(nums[head]%2!=0){
                    cnt++;
                }
            }
            if(cnt==k){
                ans++;
                int temp=head+1;
                while(temp<n && nums[temp]%2==0){
                    ans++;
                    temp++;
                }
            }
       
        
         // update the answer for current start
        
        
            // move start one step forward.
            if (tail > head)    // keep it same for all question, it basically help to handle empty subarray
            {
                tail++;
                head = tail - 1;
            }
            else
            {
                // change data  structure because removing tail element
                if(nums[tail]%2 !=0){
                     cnt--;
                }
               
            
                tail++;
            }
        }

        return ans;
    }

};