class Solution {
public:
    void solve(vector<int>& nums, int target, vector<vector<int>>& finalans, vector<int>& ans, int start) {
        
        if (target == 0) {
            finalans.push_back(ans);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            
            // skip duplicates
            if (i > start && nums[i] == nums[i - 1]) continue;

            if (nums[i] > target) break;

            ans.push_back(nums[i]);

            // move to next index (important change)
            solve(nums, target - nums[i], finalans, ans, i + 1);

            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> finalans;
        vector<int> ans;

        sort(nums.begin(), nums.end()); // important

        solve(nums, target, finalans, ans, 0);

        return finalans;
    }
};