class Solution {
public:
    void f(int ind, vector<int>& v, int tar, vector<int>& tmp, set<vector<int>>& ans){
        if(tar == 0){
            ans.insert(tmp);
            return;
        }
        if(ind == v.size()) return;
        f(ind+1, v, tar, tmp, ans);
        if(tar >= v[ind]){
            tmp.push_back(v[ind]);
            f(ind, v, tar-v[ind], tmp, ans);
            tmp.pop_back();
        }
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        set<vector<int>> ans;
        f(0, nums, target, tmp, ans);
        vector<vector<int>> res;
        for(auto& it: ans){
            res.push_back(it);
        }
        return res;
    }
};
