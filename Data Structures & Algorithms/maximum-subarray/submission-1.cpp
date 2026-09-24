class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i=0, j=0;
        int ans = INT_MIN, sum = 0;
        int n = nums.size();
        while(i<=j && j<n){
            sum += nums[j];
            ans = max(ans, sum);
            if(sum < 0){
                sum = 0;
                i = j+1;
            }
            j++;
        }
        return ans;
    }
};
