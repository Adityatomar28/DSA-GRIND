class Solution {
public:
    int solve(vector<int>& nums, int target,int n){
    if(n == 0){
        if(target == 0) return 1;
        return 0;      
    }
    int plus = solve(nums,target-nums[n-1],n-1);

    int minus = solve(nums,target+nums[n-1],n-1);

    return plus + minus;


    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(nums,target,n);
    }
};
