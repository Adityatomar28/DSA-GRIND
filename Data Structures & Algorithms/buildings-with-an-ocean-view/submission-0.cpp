class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        vector<int>finalAns;

        int maxDigit = -1;

        for(int i=n-1;i >= 0;i--){
            if(heights[i] > maxDigit){
            finalAns.push_back(i);
            maxDigit = heights[i];
            }
        }
        reverse(finalAns.begin(),finalAns.end());
        return finalAns;

        
    }
};