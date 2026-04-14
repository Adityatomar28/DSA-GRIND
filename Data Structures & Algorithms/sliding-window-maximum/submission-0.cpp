class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int>ans;
    int i = 0;
    int maxsum = 0;
    int sum = 0;

    for(int j=0;j<nums.size();j++){
    // Step 1 add current element
    sum += nums[j];
    
    //compute sum till when window hit the size k
    if(j-i+1 == k){
    maxsum = max(maxsum,sum);
    ans.push_back(maxsum);
    sum -= nums[i];
    i++;
    }
    }
    return ans;
    }
};








