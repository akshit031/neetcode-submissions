class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i=0, j=0;
        int ans = 0, sum = 0;
        int n = nums.size();
        if(n == 1) return nums[0];
        while(i<=j && j<n){
            sum += nums[j];
            if(sum < 0){
                sum = 0;
                i = j+1;
            }
            ans = max(ans, sum);
            j++;
        }
        return ans;
    }
};
