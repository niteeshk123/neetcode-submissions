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
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<int> start;
        vector<int> end;
        for(int i=0;i<intervals.size();i++){
            start.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int count = 0;
        int end_i = 0;
        for(int i=0;i<start.size();i++){
            if(start[i]<end[end_i]){
                count++;
                if(count>1){
                    return false;
                }
            }
            else if(end[end_i]<start[i]){
                count--;
                end_i++;
            }
            else{ 
                count--;  
                count++;
                end_i++;
            }
        }

        return true;
    }
};
