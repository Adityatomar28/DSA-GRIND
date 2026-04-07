class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans;
        int i = 0;

        for(int j = 0; j < nums.size(); j++) {

            // Window reached size k
            if(j - i + 1 == k) {

                int maxi = nums[i];

                // Find maximum in current window
                for(int x = i; x <= j; x++) {
                    maxi = max(maxi, nums[x]);
                }

                ans.push_back(maxi);

                // Slide window
                i++;
            }
        }

        return ans;
    }
};