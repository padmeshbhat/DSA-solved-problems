class Solution {
public:
    vector<vector<int>> matrix;
    int k, n;

    bool check(int x)
    {
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            count += upper_bound(
                matrix[i].begin(),
                matrix[i].end(),
                x
            ) - matrix[i].begin();
        }

        return count >= k;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        this->matrix = matrix;
        this->k = k;
        this->n = matrix.size();

        int lo = matrix[0][0];
        int hi = matrix[n - 1][n - 1];

        int ans = -1;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            if (check(mid))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return ans;
    }
};