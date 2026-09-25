class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        int end = v[0][1], cnt = 0;
        for(int i = 1; i<v.size();i++){
            if(v[i][0] < end){
                cnt++;
            }else{
                end = v[i][1];
            }
        }
        return cnt;
    }
};
