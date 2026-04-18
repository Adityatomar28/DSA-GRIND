class Solution {
public:
    int solve(vector<int>& nums,int i,int n){
    vector<int>dp(n+20,0);

    for(int i=n-1;i>=0;i--){
    int rob1 = nums[i] + dp[i+2];
    int rob2 = dp[i+1];
    dp[i] = max(rob1,rob2);
    
    }
    return dp[0];
    }
    int rob(vector<int>& nums) {
    int n = nums.size();
    return solve(nums,0,n);
    }
};