class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ind = 0;
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(i == ind && nums[i] == 0) return false;
            ind = max(ind, i + nums[i]);
        }
        return true;
    }
};
