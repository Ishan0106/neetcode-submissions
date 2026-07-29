class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0;
        int j = 0;
        unordered_map<char,int> mp;
        int maxi = 0;
        while(j < n){
            if(mp.find(s[j]) == mp.end()){
                mp[s[j]] = 1;
            }
            else{
                mp[s[j]]++;
            }
            if(mp[s[j]] > 1){
                while(mp[s[j]] > 1 && i < j){
                    mp[s[i]]--;
                    i++;
                }
            }
            maxi = max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};
