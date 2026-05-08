class Solution {
public:
    void solve(int i,vector<int>& nums, vector<int>&curr,vector<vector<int>>&ans){
    ans.push_back(curr);

    for(int j=i;j<nums.size();j++){
        if(j > i && nums[j] == nums[j-1])
        continue;
         curr.push_back(nums[j]);
         solve(j+1,nums,curr,ans);
         curr.pop_back();
    }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<int>curr;
    vector<vector<int>>ans;

    solve(0,nums,curr,ans);
    return ans;

    }
};
