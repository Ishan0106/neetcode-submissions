class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int maxi = 0;
        int n = prices.size();
        for(int i = 0 ; i < n ; i++){
            if(prices[i] < buy && i < n-1){
                buy = prices[i];
            }
            else if(prices[i] > buy){
                maxi = max(maxi,prices[i] - buy);
            }
        }
        return maxi;
    }
};
