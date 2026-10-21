
class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        priority_queue<pair<int, char>> pq;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push({freq[i], char('a' + i)});
            }
        }

        string ans = "";

        while (!pq.empty()) {
            auto [count, ch] = pq.top();
            pq.pop();

            int n = ans.size();

            if (n > 0 && ans[n - 1] == ch) {
                if (pq.empty()) {
                    return "";
                }

                auto [count2, ch2] = pq.top();
                pq.pop();

                ans.push_back(ch2);
                count2--;

                if (count2 > 0) {
                    pq.push({count2, ch2});
                }

                pq.push({count, ch});
            } else {
                ans.push_back(ch);
                count--;

                if (count > 0) {
                    pq.push({count, ch});
                }
            }
        }

        return ans;
    }
};
