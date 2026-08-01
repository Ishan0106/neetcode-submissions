class Solution {
public:
    bool match(vector<int>& temp,vector<int>& help){
        for(int i = 0 ;i < 52;i++){
            if(temp[i] != 0 && help[i] < temp[i])return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        if(s.length() < t.length())return "";
        vector<int> temp(52,0);
        for(auto it: t){
            if(it >= 'a' && it <= 'z'){
                temp[it-'a']++;
            }
            else{
                temp[it-'A'+26]++;
            }
        }
        vector<int> help(52,0);
        int ans = 0;
        int i = 0;
        int j = 0;
        int n = s.length();
        int curr = n+1;
        bool flag = false;
        while(j < n){
            if(s[j] >= 'a' && s[j] <= 'z'){
                help[s[j]-'a']++;
            }
            else{
                help[s[j]-'A'+26]++;
            }
            if(match(temp,help)){
                if(!flag)flag = true;
                while(match(temp,help)){
                    if(j-i+1 < curr){
                        curr = j-i+1;
                        ans = i;
                    }
                    if(s[i] >= 'a' && s[i] <= 'z'){
                        help[s[i]-'a']--;
                    }
                    else{
                        help[s[i]-'A'+26]--;
                    }
                    i++;
                }
            }
            j++;
        }
        if(flag)return s.substr(ans,curr);
        else{
            return "";
        }
    }
};
