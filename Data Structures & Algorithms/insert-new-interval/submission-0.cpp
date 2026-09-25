class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inter, vector<int>& v) {
        int n = inter.size();
        vector<vector<int>> ans;
        int i = 0;
        while(i<n && inter[i][1] < v[0]){
            ans.push_back(inter[i]);
            i++;
        }
        while(i < n && (inter[i][0] <= v[1])){
            v[0] = min(inter[i][0], v[0]);
            v[1] = max(inter[i][1], v[1]);
            i++;
        }
        ans.push_back(v);
        while(i<n){
            ans.push_back(inter[i]);
            i++;
        }
        return ans;
    }
};
