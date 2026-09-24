class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp (nums.begin(), nums.end());
        int ans = 0;
        
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]-1) == mp.end()){
                int len = 1;
                while(i<nums.size() && mp.find(nums[i]+len) != mp.end()){
                    len++;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
