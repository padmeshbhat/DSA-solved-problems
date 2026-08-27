class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int n = nums.size();

        int ans1 = -1;
        int ans2 = -1;

        
        int lo = 0;
        int hi = n - 1;

        while (lo <= hi) {

            int mid = lo + (hi - lo) / 2;

            if (nums[mid] == target) {

               
                ans1 = mid;

                
                hi = mid - 1;
            }
            else if (nums[mid] < target) {

                lo = mid + 1;
            }
            else {

                hi = mid - 1;
            }
        }

       

        lo = 0;
        hi = n - 1;

        while (lo <= hi) {

            int mid = lo + (hi - lo) / 2;

            if (nums[mid] == target) {

                
                ans2 = mid;

                
                lo = mid + 1;
            }
            else if (nums[mid] < target) {

                lo = mid + 1;
            }
            else {

                hi = mid - 1;
            }
        }

        return {ans1, ans2};
    }
};