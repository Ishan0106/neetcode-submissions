class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int tar = -nums[i];
            int j = i + 1;
            int k = n - 1;
            
            while (j < k) {
                int sum = nums[j] + nums[k];
                
                if (sum == tar) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    
                    // Skip duplicates for j. 
                    // Note: 'j < k' MUST come first to prevent out-of-bounds access!
                    while (j < k && nums[j] == nums[j + 1]) {
                        j++;
                    }
                    
                    // Skip duplicates for k.
                    // Note: k must decrease (k--)
                    while (j < k && nums[k] == nums[k - 1]) {
                        k--;
                    }
                    
                    j++;
                    k--;
                } 
                // Logic fix: conditionally move pointers based on the sum
                else if (sum < tar) {
                    j++; // Sum too small, move left pointer right
                } 
                else {
                    k--; // Sum too large, move right pointer left
                }
            }
        }
        
        return ans;
    }
};