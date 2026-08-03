class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,0);
        stack<pair<int,int>> st;
        st.push({temperatures[n-1],n-1});
        ans[n-1] = 0;
        for(int i = n-2 ; i >= 0 ; i--){
            int ele = temperatures[i];
            int index = i;
            while(!st.empty() && st.top().first <= ele){
                st.pop();
            }
            if(st.size() == 0){
                ans[i] = 0;
                st.push({temperatures[i],index});
            }
            else{
                ans[i] = st.top().second - index;
                st.push({ele,index});
            }
        }
        return ans;
    }
};
