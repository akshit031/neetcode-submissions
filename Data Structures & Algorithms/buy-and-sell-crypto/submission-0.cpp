class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        int mini = v[0], ans = 0;
        for(int i= 1;i<n;i++){
            ans = max(ans, v[i]-mini);
            mini = min(mini, v[i]);
        }
        return ans;
    }
};
