class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> vec(26,0);
        for(auto ch : s){
            vec[ch-'a']++;
        }
        for(auto ch : t){
            vec[ch-'a']--;
        }
        for(auto it : vec){
            if(it != 0){
                return false;
            }
        }
        return true;
    }
};
