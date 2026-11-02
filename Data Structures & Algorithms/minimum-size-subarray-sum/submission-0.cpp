
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int left = 0;
        int sum = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < nums.size(); right++) {

            // Expand the window
            sum += nums[right];

            // Shrink the window while sum >= target
            while (sum >= target) {

                int len = right - left + 1;

                minLen = min(minLen, len);

                sum -= nums[left];
                left++;
            }
        }

        if (minLen == INT_MAX)
            return 0;

        return minLen;
    }
};
