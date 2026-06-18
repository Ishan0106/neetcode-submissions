class Solution {
public:
    void helper(vector<int> &temp,vector<vector<int>> &ans, vector<int>& nums, int ind, int &curr, int target){
        if(ind == nums.size()){
            if(curr == target){
                ans.push_back(temp);
            }
            return;
        }
        if(curr + nums[ind] <= target){
            temp.push_back(nums[ind]);
            curr += nums[ind];
            helper(temp,ans,nums,ind,curr,target);
            curr -= nums[ind];
            temp.pop_back();
        }
        helper(temp,ans,nums,ind+1,curr,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int curr = 0;
        helper(temp,ans,nums,0,curr,target);
        return ans;
    }
};
