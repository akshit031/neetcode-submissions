class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        int n = inter.size();
        if(n == 0) return {};
        sort(inter.begin(), inter.end());
        vector<vector<int>> ans;
        int start = inter[0][0], end = inter[0][1];
        for(int i=1;i<n;i++){
            if(end >= inter[i][0]){
                end = max(end, inter[i][1]);
                continue;
            }
            ans.push_back({start, end});
            start = inter[i][0], end = inter[i][1];
        }
        ans.push_back({start, end});
        return ans;
    }
};
