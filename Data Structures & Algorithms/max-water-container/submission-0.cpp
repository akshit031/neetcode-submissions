class Solution {
public:
    int maxArea(vector<int>& v) {
        int n = v.size();
        int l = 0, r = n-1;
        int ans = 0;
        while(l<r){
            int x = min(v[l], v[r]);
            ans = max(ans, x*(r-l));
            if(v[l] < v[r]) l++;
            else r--;
        }
        return ans;
    }
};
