class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int num:nums){
        mp[num]++;
        }
        //step 2 store freq
        vector<pair<int,int>> freq;
        for(auto &c:mp){
            freq.push_back({c.first,c.second});

        }
        //sort by freq ,descending
        sort(freq.begin(),freq.end(),
            [](const auto&a ,const auto &b){
                return a.second > b.second;
            });
        
        vector<int>ans;

        for(int i=0;i<k;i++){
            ans.push_back(freq[i].first);
        }
        return ans;
        
    }
};
