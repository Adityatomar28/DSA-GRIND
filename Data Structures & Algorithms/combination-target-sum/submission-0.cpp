class Solution {
public:
    void solve(vector<int>& nums, int target,vector<vector<int>>&finalans,vector<int>&ans,int i){
    if(target == 0){
    finalans.push_back(ans);
    return;
    }
    if(i >= nums.size()) return;

    //inc
    if(nums[i] <= target){
    ans.push_back(nums[i]);
    solve(nums,target-nums[i],finalans,ans,i);
    ans.pop_back();
    }
    solve(nums,target,finalans,ans,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    vector<vector<int>>finalans;
    vector<int>ans;

    solve(nums,target,finalans,ans,0); 
    return finalans;
    }
};
