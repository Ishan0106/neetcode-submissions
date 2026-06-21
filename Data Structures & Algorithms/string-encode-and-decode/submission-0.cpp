#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded_str = "";
        for (const string& s : strs) {
            encoded_str += to_string(s.length()) + "#" + s;
        }
        return encoded_str;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strs;
        size_t i = 0;
        
        while (i < s.length()) {
            // Find the index of the next '#' starting from index i
            size_t pos = s.find('#', i);
            
            // Extract the length of the string
            int length = stoi(s.substr(i, pos - i));
            
            // Extract the actual string using the parsed length
            string str = s.substr(pos + 1, length);
            decoded_strs.push_back(str);
            
            // Move the pointer forward to the start of the next block
            i = pos + 1 + length;
        }
        
        return decoded_strs;
    }
};