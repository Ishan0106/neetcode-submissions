class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp;
        for(char ch: s1){
            mp[ch]++;
        }
        int cnt = mp.size();
        int i = 0;
        int j = 0;
        int n = s2.size();
        while(j < n){
            if(mp.find(s2[j]) != mp.end()){
                mp[s2[j]]--;
                if(mp[s2[j]] == 0){
                    cnt--;
                }
            }
            if(j-i+1 == s1.size()){
                if(cnt == 0)return true;
                else{
                    if(mp.find(s2[i]) != mp.end()){
                        mp[s2[i]]++;
                        if(mp[s2[i]] == 1){
                            cnt++;
                        }
                    }
                    i++;
                }
            }
            j++;
        }
        return false;
    }
};
