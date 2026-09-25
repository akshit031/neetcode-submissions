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
    bool canAttendMeetings(vector<Interval>& v) {
        sort(v.begin(), v.end(), [](Interval& a, Interval& b){
            return a.start < b.start;
        });
        int end = v[0].end;
        for(int i = 1; i<v.size();i++){
            if(v[i].start < end){
                return false;
            }else{
                end = v[i].end;
            }
        }
        return true;
    }
};
