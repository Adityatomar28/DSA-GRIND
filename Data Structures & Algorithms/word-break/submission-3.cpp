// class Solution {
// public:
//     bool solve(string s ,vector<string>&wordDict,int i){
//     if(i == s.size()) return true;

//     for(string &word:wordDict){
//     if(s.substr(i,word.size()) == word){
//         if(solve(s,wordDict,i+word.size()));
//         return true;
//     }
//     }
//     return false;
//     }
//     bool wordBreak(string s, vector<string>& wordDict) {
//     return solve(s,wordDict,0);
//     }
// };
// class Solution {
// public:
//     bool solve(int i,string s, vector<string>& wordDict){
//     if(i == s.size()) return true;

//     for(string &word:wordDict){
//         if(s.substr(i,word.size()) == word){
//             if(solve(i+word.size(),s,wordDict)){
//             return true;
//             }
//         }
//     }
//     return false;
//     }
//     bool wordBreak(string s, vector<string>& wordDict) {
    
//     return solve(0,s,wordDict);
//     }
// };

class Solution {
public:
    unordered_map<int, bool> memo;

    bool wordBreak(string s, vector<string>& wordDict) {
        memo[s.length()] = true;
        return dfs(s, wordDict, 0);
    }

    bool dfs(string& s, vector<string>& wordDict, int i) {
        if (memo.find(i) != memo.end()) {
            return memo[i];
        }

        for (const string& w : wordDict) {
            if (i + w.length() <= s.length() &&
                s.substr(i, w.length()) == w) {
                if (dfs(s, wordDict, i + w.length())) {
                    memo[i] = true;
                    return true;
                }
            }
        }
        memo[i] = false;
        return false;
    }
};

