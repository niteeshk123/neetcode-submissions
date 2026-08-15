class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int len = heights.size();
        int right = len-1;
        int left_max = heights[left];
        int right_max = heights[right];
        int res = INT_MIN;
        while(left<right){
            left_max = max(left_max, heights[left]);
            right_max = max(right_max, heights[right]);
            int temp = min(left_max, right_max);
            temp = temp*(right-left);
            res = max(res, temp);
            if(heights[left]>heights[right]){
                right--;
            }
            else {
                left++;
            }
        }
        return res;
        
    }
};
