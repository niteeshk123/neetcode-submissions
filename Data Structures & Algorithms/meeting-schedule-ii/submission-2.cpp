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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start;
        vector<int> end;

        for(int i=0;i<intervals.size();i++){
            start.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int end_i=0;
        int count = 0;
        int res = count;
        for(int i=0;i<start.size();i++){
            if(start[i]<end[end_i]){
                count++;
                res=max(res, count);
            }
            else if(end[end_i]>start[i]){
                end_i++;
                count--;
            }
            else{
                end_i++;
            }
        }
        return res;

    }
};
