class Solution {
public:
    // Helper function with memoization
    int solve(vector<int>& nums, int s, int e, vector<int>& dp) {
        if (s > e) {
            return 0;
        }

        if (dp[s] != -1) {
            return dp[s];
        }

        int rob = nums[s] + solve(nums, s + 2, e, dp);
        int skip = solve(nums, s + 1, e, dp);

        dp[s] = max(rob, skip);
        return dp[s];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        // Rob houses from index 0 to n-2
        vector<int> dp1(n, -1);
        int rob1 = solve(nums, 0, n - 2, dp1);

        // Rob houses from index 1 to n-1
        vector<int> dp2(n, -1);
        int rob2 = solve(nums, 1, n - 1, dp2);

        return max(rob1, rob2);
    }
};
