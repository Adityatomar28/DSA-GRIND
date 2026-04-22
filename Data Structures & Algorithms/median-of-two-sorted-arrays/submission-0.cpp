class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int>ans;
    int n = nums1.size(),m = nums2.size();
    for(int i=0;i<n;i++){
    ans.push_back(nums1[i]);

    }
    for(int j=0;j<m;j++){
    ans.push_back(nums2[j]);
    }
    sort(ans.begin(),ans.end());

    int total = ans.size();
    // Means it is even;
    if(total % 2 == 0){
    return (ans[total/2 - 1] + ans[total/2]) / 2.0;
    }else{
    return ans[total/2];
    }


    }
};
