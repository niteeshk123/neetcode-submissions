class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<int> current = intervals[0];
        vector<vector<int>> res;

        for(int i; i<intervals.size(); i++){
            if(current[1]>=intervals[i][0]){
                current[1] = max(current[1], intervals[i][1]);
            }else {
                res.push_back(current);
                current = intervals[i];
            }
        }

        res.push_back(current);

        return res;
    }
};
