class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int tail = 0, head = -1;

        // data structure for current window
        unordered_map<char, int> mp;

        // answer
        long long ans = 0;
        int n=s.length();

        while (tail < n)
        {
            // Expand head
            while (head + 1 < n)
            {
                int x = s[head + 1];

                // x is new and we already have K distinct elements
                if (mp.find(x) != mp.end() )
                {
                    break;
                }

                head++;

                // Include element in map
                mp[s[head]]++;
            }

            // Count all valid subarrays starting at tail
            ans=max(ans,(long long)head-tail+1);
            // Move tail
            if (tail > head)
            {
                tail++;
                head = tail - 1;
            }
            else
            {
                // Remove a[tail]
                mp[s[tail]]--;

                if (mp[s[tail]] == 0)
                {
                    mp.erase(s[tail]);
                }

                tail++;
            }
        }

       return ans;
   

    }
};