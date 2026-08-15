class Solution {
public:
    static bool comparator(vector<int> a, vector<int> b){
        if(a[0]<b[0]){
            return true;
        }
        return false;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comparator);
        int res = 0;
        int end = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<end){
                res++;
                end = min(end, intervals[i][1]);
            }
            else{
                end = intervals[i][1];
            }
        }
        return res;
    }
};
