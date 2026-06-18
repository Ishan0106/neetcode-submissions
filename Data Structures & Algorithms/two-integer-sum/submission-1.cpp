class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> indexedNums;
        for (int i = 0; i < nums.size(); ++i) {
            indexedNums.push_back({nums[i], i});
        }
        sort(indexedNums.begin(), indexedNums.end());
        int i = 0;
        int j = indexedNums.size() - 1;
        while(i != j){
            if(indexedNums[i].first + indexedNums[j].first == target){
                int first = indexedNums[i].second;
                int second = indexedNums[j].second;
                return {min(first, second), max(first, second)};
            }
            else if(indexedNums[i].first + indexedNums[j].first > target){
                j--;
            }
            else{
                i++;
            }
        }
        return {};
    }
};
