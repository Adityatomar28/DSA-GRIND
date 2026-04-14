class Solution {
public:

    int solve(vector<int>& nums, int index, int prev, int count) {
        if(index == nums.size())
            return count;

        int include = count;
        if(prev == -1 || nums[index] == prev + 1) {
            include = solve(nums, index + 1,nums[index],count + 1);
        }
        int exclude = solve(nums,index + 1,prev,count);

        return max(include, exclude);
    }

    int longestConsecutive(vector<int>& nums) {

        if(nums.empty())
        return 0;

        sort(nums.begin(), nums.end());

        return solve(nums, 0, -1, 0);
    }
};