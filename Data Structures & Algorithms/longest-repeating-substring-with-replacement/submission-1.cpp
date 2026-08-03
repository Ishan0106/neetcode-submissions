class Solution {
public:
    int characterReplacement(string s, int k) {
         int i = 0;
         int j = 0;
         vector<int> vec(26,0);
         int n = s.length();
         int maxi = 0;
         int ans = 1;
         while(j < n){
            vec[s[j]-'A']++;
            maxi = max(maxi,vec[s[j]-'A']);
            if((j-i+1)-maxi <= k){
                ans = max(ans,j-i+1);
            }
            else{
                vec[s[i]-'A']--;
                i++;
            }
            j++;
         }
         return ans;
    }
};
