class Solution {
public:
    int f(int ind, int amt, vector<int>& v, vector<vector<int>>& dp){
        if(amt == 0) return 0;
        if(ind == v.size()) return 1e9;
        if(dp[ind][amt] != -1) return dp[ind][amt];
        int take = 1e9;
        if(amt >= v[ind]){
            take = 1 + f(ind, amt - v[ind], v, dp);
        }
        int notake = f(ind+1, amt, v, dp);
        return dp[ind][amt] = min(take, notake);
    }
    int coinChange(vector<int>& v, int amount) {
        int n = v.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = f(0, amount, v, dp);
        return ans == 1e9 ? -1 : ans;
    }
};
