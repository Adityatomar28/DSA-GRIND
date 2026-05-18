class Solution {
public:
    void solve(vector<string>&ans,string final,int open,int close,int n){
    if(n == open && n == close){
    ans.push_back(final);
    return;
    }
    if(open > close) solve(ans,final + ')',open,close+1,n);

    if(open < n) solve(ans,final + '(',open+1,close,n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(ans,"",0,0,n);
        return ans;
    }
};
