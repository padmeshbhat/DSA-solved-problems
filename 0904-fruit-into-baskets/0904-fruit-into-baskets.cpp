class Solution {
public:
    int totalFruit(vector<int>& fruits) {
         int tail = 0, head = -1;

        // data structure for current window
        map<int, int> mp;

        // answer
        int ans = 0;
        int n=fruits.size();

        while (tail < n)
        {
            // Expand head
            while (head + 1 < n)
            {
                int x = fruits[head + 1];

                // x is new and we already have K distinct elements
                if (mp.find(x) == mp.end() && mp.size() == 2)
                {
                    break;
                }

                head++;

                // Include element in map
                mp[fruits[head]]++;
            }

            // Count all valid subarrays starting at tail
            if (head >= tail)
            {
                ans = max(ans,head-tail+1);
            }

            // Move tail
            if (tail > head)
            {
                tail++;
                head = tail - 1;
            }
            else
            {
                // Remove a[tail]
                mp[fruits[tail]]--;

                if (mp[fruits[tail]] == 0)
                {
                    mp.erase(fruits[tail]);
                }

                tail++;
            }
        }

        return ans;
    }
   
};