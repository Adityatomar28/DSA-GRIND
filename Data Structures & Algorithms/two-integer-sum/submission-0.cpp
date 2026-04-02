class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int>need;
    for(int i=0;i<nums.size();i++){
    int final = target-nums[i];

    if(need.find(final) != need.end()){
        return {need[final],i};
    }
    need[nums[i]] = i;
    }
    return {};
    }
};
