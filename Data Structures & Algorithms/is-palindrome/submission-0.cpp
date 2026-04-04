class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;

        while (i < j) {

            // Skip non-alphanumeric from left
            while (i < j && !isalnum(s[i])) {
                i++;
            }

            // Skip non-alphanumeric from right
            while (i < j && !isalnum(s[j])) {
                j--;
            }

            // Compare ignoring case
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }

            // Move pointers
            i++;
            j--;
        }

        return true;
    }
};