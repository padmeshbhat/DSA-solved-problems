class Solution {
public:
    vector<int> position;
    int n, m;

    bool check(int x)
    {
        int ball = 1;
        int last = position[0];

        for (int i = 1; i < n; i++)
        {
            if (position[i] - last >= x)
            {
                ball++;
                last = position[i];
            }
        }

        return ball >= m;
    }

    int maxDistance(vector<int>& pos, int balls)
    {
        position = pos;
        m = balls;
        n = position.size();

        sort(position.begin(), position.end());

        int lo = 1;
        int high = position[n - 1] - position[0];

        int ans = -1;

        while (lo <= high)
        {
            int mid = lo + (high - lo) / 2;

            if (check(mid))
            {
                // mid is possible
                // Try for a larger minimum distance
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                // mid is not possible
                // Try a smaller distance
                high = mid - 1;
            }
        }

        return ans;
    }
};