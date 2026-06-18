class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> help1(n, 1);
        vector<int> help2(n, 1);
        vector<int> ans(n);

        // help1[i] contains the product of all elements to the LEFT of i
        for(int i = 1; i < n; i++){
            help1[i] = help1[i-1] * nums[i-1];
        }

        // help2[i] contains the product of all elements to the RIGHT of i
        for(int i = n-2; i >= 0; i--){
            help2[i] = help2[i+1] * nums[i+1];
        }

        // The answer is simply the left product multiplied by the right product
        for(int i = 0; i < n; i++){
            ans[i] = help1[i] * help2[i];
        }

        return ans;
    }
};