class Solution {
public:

    int solve(vector<int>& nums,
              int index,
              int prev,
              int count)
    {
        if(index == nums.size())
            return count;

        // skip duplicate
        if(prev != -1 && nums[index] == prev)
            return solve(nums,index+1,prev,count);

        int include = count;

        // include case
        if(prev == -1 || nums[index] == prev + 1)
        {
            include = solve(
                        nums,
                        index + 1,
                        nums[index],
                        count + 1);
        }

        // IMPORTANT FIX: reset sequence
        int exclude =
            solve(nums,
                  index + 1,
                  -1,
                  0);

        return max(include, exclude);
    }

    int longestConsecutive(vector<int>& nums)
    {
        if(nums.empty())
            return 0;

        sort(nums.begin(), nums.end());

        return solve(nums, 0, -1, 0);
    }
};