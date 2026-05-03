class Solution {
public:
    int solve(vector<int>& nums,int n,int sum){
    if(sum == 0) return true;
    if(n == 0)   return false;

    if(nums[n-1] <= sum){
    return solve(nums,n-1,sum-nums[n-1]) || solve(nums,n-1,sum);
    }else{
    return solve(nums,n-1,sum);
    }
    return true;
    }
    bool canPartition(vector<int>& nums) {
    int total = 0;

    for(int x:nums){
    total += x;
    }
    if(total%2 != 0) return false;

    return solve(nums,nums.size(),total/2);

    }
};
