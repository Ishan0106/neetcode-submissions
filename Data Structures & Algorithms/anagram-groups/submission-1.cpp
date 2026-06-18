// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>> ans;
//         unordered_map<string,vector<string>> mp;
//         for(auto it : strs){
//             string temp = it;
//             sort(temp.begin(),temp.end());
//             mp[temp].push_back(it);
//         }
//         for(auto it : mp){
//             ans.push_back(it.second);
//         }
//         return ans;
//     }
// };

// above is N*klogk

//below is N*K

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for (const string& s : strs) {
            // 1. Count frequencies of each character
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }
            
            // 2. Build a unique string key from the frequency array
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += to_string(count[i]) + "#"; 
                // We use '#' as a delimiter to prevent mixing up counts 
                // like "1" and "11" for different letters.
            }
            
            // 3. Group the original string under this unique key
            mp[key].push_back(s);
        }
        
        // 4. Collect the results
        vector<vector<string>> ans;
        for (auto& pair : mp) {
            ans.push_back(pair.second); // pair.second is the vector of anagrams
        }
        
        return ans;
    }
};