class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                int length = 1;
                while (numSet.find(num + length) != numSet.end()) {
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};

/*
Bhai isko phir se krlena ek baar 
acha question bhi hai 


The input array may contain duplicate values. Using a set 
automatically handles this, but if you iterate over the original
array instead of the set, you may process the same sequence
multiple times, wasting computation.
*/