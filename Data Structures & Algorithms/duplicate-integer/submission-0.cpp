class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        return st.size() != n;
    }
};