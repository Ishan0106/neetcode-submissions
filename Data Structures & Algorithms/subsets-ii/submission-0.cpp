class Solution {
public:
    void helper(int ind, vector<vector<int>> &ans,vector<int> &temp, vector<int> &nums){
        ans.push_back(temp);
        for(int i = ind; i < nums.size();i++){
            if(i != ind && nums[i] == nums[i-1])continue;
            temp.push_back(nums[i]);
            helper(i+1,ans,temp,nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp= {};
        helper(0,ans,temp,nums);
        return ans;
    }
};
