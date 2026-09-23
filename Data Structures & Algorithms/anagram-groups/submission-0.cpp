class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        unordered_map<string, vector<string>> mp;
        
        for(auto &val:s){
            string sor = val;
            sort(sor.begin(), sor.end());
            mp[sor].push_back(val);
        }
        vector<vector<string>> ans;
        for(auto &it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
