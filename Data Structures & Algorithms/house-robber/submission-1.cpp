class Solution {
public:
    int rob(vector<int>& v) {
        int n = v.size();
        if(n == 1) return v[0];
        if(n == 2) return max(v[0], v[1]);
        vector<int> dp(n, 0);
        dp[0] = v[0]; 
        dp[1] = v[1];
        for(int i=2;i<n;i++){
            int take = v[i] + dp[i-2];
            int notake = dp[i-1];
            dp[i] = max(take, notake);
        }
        return dp[n-1];
    }
};
