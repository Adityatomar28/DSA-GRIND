class Solution {
public:

    string encode(vector<string>& strs) {
    string result = "";

    for(string &s:strs){
        result += to_string(s.length()) + "#" + s;
    }
    return result;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int i = 0;

        while(i < s.length()){
            int j = i;
        
        while(s[j] != '#' && j < s.length()){
            j++;
        }
        int length = stoi(s.substr(i,j-i));

        string word = s.substr(j+1,length);

        ans.push_back(word);
        i = j+1+length;
        }
        return ans;
    }
};
