// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> help1(n, 1);
//         vector<int> help2(n, 1);
//         vector<int> ans(n);

//         // help1[i] contains the product of all elements to the LEFT of i
//         for(int i = 1; i < n; i++){
//             help1[i] = help1[i-1] * nums[i-1];
//         }

//         // help2[i] contains the product of all elements to the RIGHT of i
//         for(int i = n-2; i >= 0; i--){
//             help2[i] = help2[i+1] * nums[i+1];
//         }

//         // The answer is simply the left product multiplied by the right product
//         for(int i = 0; i < n; i++){
//             ans[i] = help1[i] * help2[i];
//         }

//         return ans;
//     }
// };


// optimsed below 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        
        // Pass 1: Calculate left products and store them in ans
        int leftProduct = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = leftProduct;        // Store product of everything to the left
            leftProduct *= nums[i];      // Update running left product
        }
        
        // Pass 2: Calculate right products on the fly and multiply into ans
        int rightProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= rightProduct;      // Multiply left product by right product
            rightProduct *= nums[i];     // Update running right product
        }
        
        return ans;
    }
};