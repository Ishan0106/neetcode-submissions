class Solution {
public:
    void solve(int ind,vector<string>& ans,unordered_map<char,string>& mp,string& temp,string& digits){
        if(ind >= digits.length()){
            ans.push_back(temp);
            return;
        }
        for(auto it: mp[digits[ind]]){
            temp += it;
            solve(ind+1,ans,mp,temp,digits);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)return {};
        unordered_map<char,string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        string temp = "";
        vector<string> ans;
        solve(0,ans,mp,temp,digits);
        return ans;
    }
};
