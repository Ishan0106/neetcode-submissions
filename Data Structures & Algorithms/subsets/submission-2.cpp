class Solution {
public:
    void helper(int ind, vector<vector<int>> &ans, vector<int> temp,vector<int>& nums, int n){
        if(ind == n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        helper(ind+1,ans,temp,nums,n);
        temp.pop_back();
        helper(ind+1,ans,temp,nums,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0,ans,temp,nums,n);
        return ans;
    }
};
