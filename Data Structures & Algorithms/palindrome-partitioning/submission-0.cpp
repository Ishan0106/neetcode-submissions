class Solution {
public:
    bool isvalid(string s, int start,int end){
        while(start <= end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
    void solve(int ind,vector<vector<string>>& ans, vector<string>& temp, string s){
        if(ind >= s.length()){
            ans.push_back(temp);
            return;
        }
        for(int i = ind ; i < s.length(); i++){
            if(isvalid(s,ind,i)){
                temp.push_back(s.substr(ind,i-ind+1));
                solve(i+1,ans,temp,s);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0,ans,temp,s);
        return ans;
    }
};
