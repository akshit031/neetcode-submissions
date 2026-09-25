class Solution {
public:
    int f(int i, vector<int>& v, int prev,  vector<vector<int>>& dp){
        if(i == v.size()) return 0;

        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        
        dp[i][prev+1] = f(i+1, v, prev, dp);
        if(prev == -1 || v[i] > v[prev]){
            dp[i][prev+1] = max(1 + f(i+1, v, i, dp), dp[i][prev+1]);
        }
        return dp[i][prev+1];
    }
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(0, v, -1, dp);
    }
};
