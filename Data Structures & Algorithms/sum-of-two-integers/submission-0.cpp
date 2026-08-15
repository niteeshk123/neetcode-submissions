class Solution {
public:
    int getSum(int a, int b) {
        int res = 0;
        int carry = 0;
        for(int i=0;i<32;i++){
            int A = 1&(a>>i);
            int B = 1&(b>>i);
            if(A==1 && B==1){
                if(carry==1){
                    carry=1;
                    res|=(1<<i);
                }
                else{
                    carry=1;
                    res|=(0<<i);
                }
            }
            else if(A==1 || B==1){
                if(carry==1){
                    carry=1;
                    res|=(0<<i);
                }
                else{
                    res|=(1<<i);
                    carry=0;
                }
            }
            else{
                if(carry==1){
                    res|=(1<<i);
                    carry=0;
                }
            }

        }
                    return res;

    }
};
