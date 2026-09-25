/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& v) {
        int n = v.size();
        if(n == 0) return 0;
        sort(v.begin(), v.end(), [](Interval& a, Interval& b){
            return a.start < b.start;
        });
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto& x: v){
            if(!pq.empty() && pq.top() <= x.start){
                pq.pop();
            }
            pq.push(x.end);
        }
        return pq.size();
    }
};
