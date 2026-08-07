class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> lsmall(n,-1);
        vector<int> rsmall(n,-1);
        rsmall[n-1] = n+1;
        stack<pair<int,int>> st;
        st.push({heights[n-1],n});
        for(int  i = n-2 ; i >= 0 ; i--){
            while(!st.empty() && st.top().first >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                rsmall[i] = n+1;
            }
            else{
                rsmall[i] = st.top().second;
            }
            st.push({heights[i],i+1});
        }
        lsmall[0] = 0;
        stack<pair<int,int>> st1;
        st1.push({heights[0],1});
        for(int i = 1 ; i < n ; i++){
            while(!st1.empty() && st1.top().first >= heights[i]){
                st1.pop();
            }
            if(st1.empty()){
                lsmall[i] = 0;
            }
            else{
                lsmall[i] = st1.top().second;
            }
            st1.push({heights[i],i+1});
        }
        int area = 0;
        for(int i  = 0 ; i < n ; i++){
            int width = rsmall[i]-lsmall[i]-1;
            area = max(area,width*heights[i]);
        }
        return area;
    }
};
