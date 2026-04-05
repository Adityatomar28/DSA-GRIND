class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;

        int amount = 0;
        int maxi = 0;

        while (i < j) {

            amount = min(heights[i], heights[j]);

            int final = amount * (j - i);

            maxi = max(maxi, final);

            if (heights[i] < heights[j]) {
                i++;
            }
            else {
                j--;
            }
        }

        return maxi;
    }
};
