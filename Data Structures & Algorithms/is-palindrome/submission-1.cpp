
class Solution {
public:
    bool solve(string s, int right, int left) {
        while (left < right) {
            if (!isalnum(s[left])) {
                left++;
            }
            else if (!isalnum(s[right])) {
                right--;
            }
            else if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            else {
                left++;
                right--;
            }
        }
        return true;
    }

    bool isPalindrome(string s) {
        int right = s.length() - 1;
        int left = 0;

        return solve(s, right, left);
    }
};
