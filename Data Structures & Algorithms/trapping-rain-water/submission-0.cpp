class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==0 || n == 1 || n==2){
            return 0;
        }
        int l = 0;
        int l_max = height[0];
        int r = n-1;
        int r_max = height[n-1];
        int count = 0;
        while(l<r){
            if(height[l]<=height[r]){
                if(height[l]<l_max){
                    count+=(l_max - height[l]);
                    l++;
                } else {
                    l_max = height[l];
                    l++;
                }
            } else {
                if(height[r] < r_max){
                    count+=(r_max-height[r]);
                    r--;
                } else {
                    r_max = height[r];
                    r--;
                }
            }
        }

        return count;
    }
};
