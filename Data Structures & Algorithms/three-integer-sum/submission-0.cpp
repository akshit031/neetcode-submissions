class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        int n = v.size();
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i>0 && v[i-1] == v[i]) continue;

            int l = i+1, r = n-1;
            while(l < r){
                int sum = v[i] + v[l] + v[r];
                if(sum == 0){
                    ans.push_back({v[i], v[l], v[r]});
                    l++;
                    r--;
                    while(l<r && v[l] == v[l-1])l++;
                    while(l<r && v[r] == v[r+1])r--;
                }else if(sum < 0)l++;
                else r--;
            }
        }
        
        return ans;
    }
};
