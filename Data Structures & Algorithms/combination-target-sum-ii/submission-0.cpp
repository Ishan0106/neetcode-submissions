class Solution {
public:
    void helper(int ind,int &curr, vector<vector<int>>& ans, vector<int> &temp, vector<int>& candidates, int target){
        if(curr == target){
            ans.push_back(temp);
            return;
        }
        for(int i = ind; i < candidates.size(); i++){
            if(i > ind && candidates[i] == candidates[i-1])continue;
            if(curr + candidates[i] > target)return;
            curr += candidates[i];
            temp.push_back(candidates[i]);
            helper(i+1,curr,ans,temp,candidates,target);
            curr -= candidates[i];
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int curr = 0;
        helper(0,curr,ans,temp,candidates,target);
        return ans;
    }
};
