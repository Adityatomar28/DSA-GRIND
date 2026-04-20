class Solution {
public:

    string ans = "";

    bool isPalindrome(string &s, int left, int right) {

        if (left >= right)
            return true;

        if (s[left] != s[right])
            return false;

        return isPalindrome(s, left + 1, right - 1);
    }

    void solve(string &s, int start, int end) {

        if (end == s.size())
            return;

        if (start > end) {
            solve(s, 0, end + 1);
            return;
        }

        if (isPalindrome(s, start, end)) {

            if (end - start + 1 > ans.size()) {
                ans = s.substr(start,
                               end - start + 1);
            }
        }

        solve(s, start + 1, end);
    }

    string longestPalindrome(string s) {

        solve(s, 0, 0);

        return ans;
    }
};