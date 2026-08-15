class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m+n-2;
        int r = m-1;
        int val=1;
        for(int i=1; i<=r; i++){
            val = val*(N-i+1)/i;
        }

        return val;
    }
};
