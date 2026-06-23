class Solution {
public:
    void solve(vector<string>& ans, string& temp, int& open, int& close, int n){
        if(close > open){
            return;
        }
        if(open + close == n){
            ans.push_back(temp);
            return;
        }
        if(open < n/2){
            temp += '(';
            open++;
            solve(ans,temp,open,close,n);
            open--;
            temp.pop_back();
        }
        if(close < n/2){
            temp += ')';
            close++;
            solve(ans,temp,open,close,n);
            close--;
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        int open = 0;
        int close = 0;
        solve(ans,temp,open,close,2*n);
        return ans;
    }
};
