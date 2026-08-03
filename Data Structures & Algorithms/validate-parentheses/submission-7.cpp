class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto it: s){
            if(it == '[' || it == '(' || it == '{'){
                st.push(it);
            }
            else{
                if(it == ')' && (st.size() > 0 && st.top() != '(') || st.size() == 0){
                    return false;
                }
                else if(it == '}' && (st.size() > 0 && st.top() != '{') || st.size() == 0){
                    return false;
                }
                else if(it == ']' && (st.size() > 0 && st.top() != '[') || st.size() == 0){
                    return false;
                }
                else{
                    if(st.size() > 0)st.pop();
                }
            }
        }
        if(st.size() > 0)return false;
        return true;
    }
};
