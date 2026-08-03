class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto it: tokens){
            if(it == "+" || it == "-" || it == "*" || it == "/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int res = 0;
                if(it == "+")res = a+b;
                else if(it == "-")res = b - a;
                else if(it == "*")res = a*b;
                else{
                    res = b/a;
                }
                st.push(res);
            }
            else{
                st.push(stoi(it));
            }
        }
        return st.top();
    }
};
