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
        for(auto interval:intervals){
            start.push_back(interval.start);
            end.push_back(interval.end);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int count;
        int i = 0;
        int j = 0;
        count = 0;
        int res = 0;
        while(i<start.size()){
            if(start[i]<end[j]){
                count++;
                i++;
                res = max(res, count);
            } else {
                count--;
                j++;
                // i++;
            }
        }

        return res;
    }
};
