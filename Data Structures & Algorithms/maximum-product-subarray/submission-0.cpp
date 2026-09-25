class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int pre = 0, suf = 0;
        for(int i=0;i<n;i++){
            pre = nums[i] * (pre == 0 ? 1 : pre);
            suf = nums[n-1-i] * (suf == 0 ? 1 : suf);
            ans = max(ans, max(pre, suf));
        }
        return ans;
    }
};
