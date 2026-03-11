class Solution {
public:
const int MOD=1e9+7;
    int concatenatedBinary(int n) {
        long long ans=0;
        for(int i=1;i<=n;i++){
            int digits=log2(i)+1;
            ans=((ans<<digits)%MOD+i)%MOD;

        }
        return ans;
    }
};
