class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLength = INT_MAX;
        int ans = 0;
        int left = 0;
 

        for(int r=0;r<nums.size();r++){
            ans += nums[r];

            while(ans >= target){
            int len = r-left+1;
            minLength = min(minLength,len);
            ans -= nums[left];
            left++;
            }
        }
        if(minLength == INT_MAX)
        return 0;

        return minLength;


    }
};