class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int n = heights.size();
        int j = n-1;
        int maxi = 0;
        while(i < j){
            maxi = max(maxi, min(heights[i],heights[j]) * (j-i));
            if(heights[i] < heights[j]){
                i++;
            }
            else if(heights[i] > heights[j]){
                j--;
            }
            else{
                i++;
                j--;
            }
        }
        return maxi;
    }
};
