class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size())
            return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        int left = 0;

        // Build frequency of s1
        for (char ch : s1) {
            freq1[ch - 'a']++;
        }

        for (int right = 0; right < s2.size(); right++) {

            // Add character to window
            freq2[s2[right] - 'a']++;

            // Maintain fixed window size
            if (right - left + 1 > s1.size()) {
                freq2[s2[left] - 'a']--;
                left++;
            }

            // Check permutation match
            if (freq1 == freq2)
                return true;
        }

        return false;
    }
};