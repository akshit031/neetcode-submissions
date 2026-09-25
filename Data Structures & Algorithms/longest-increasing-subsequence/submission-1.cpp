class Solution {
public:
    // int f(int i, vector<int>& v, int j,  vector<vector<int>>& dp){
    //     if(i == v.size()) return 0;

    //     if(dp[i][j+1] != -1) return dp[i][j+1];
        
    //     dp[i][j+1] = f(i+1, v, j, dp);
    //     if(j == -1 || v[i] > v[j]){
    //         dp[i][j+1] = max(1 + f(i+1, v, i, dp), dp[i][j+1]);
    //     }
    //     return dp[i][j+1];
    // }
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                dp[i][j+1] = dp[i+1][j+1];
                if(j == -1 || v[i] > v[j]){
                    dp[i][j+1] = max(1 + dp[i+1][i+1], dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};
