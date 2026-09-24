class Solution {
public:
    int f(int i, int n, vector<int>& v, vector<int>& dp){
        if(i > n)return 0;
        if(dp[i] != -1) return dp[i];
        int take = v[i] + f(i+2, n, v, dp);
        int notake = f(i+1, n, v, dp);
        return dp[i] = max(take, notake);
    }
    int rob(vector<int>& v) {
        int n = v.size();
        vector<int> dp(n, -1);
        int one = f(0, n-2, v, dp);
        for(auto& val:dp) val = -1;
        int two = f(1, n-1, v, dp);
        return max(one, two);
    }
};
