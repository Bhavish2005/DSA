class Solution {
public:
    const int MOD=1e9+7;
    int t[201][201][2];
    int helper(int zero, int one, bool wasOne, int limit){
        if(zero==0 && one==0){
            return 1;
        }   
        if(t[zero][one][wasOne]!=-1)
        return t[zero][one][wasOne];
        long long res=0;
        if(wasOne){
            for(int i=1;i<=min(limit, zero);i++)
                res=(res+helper(zero-i,one,false,limit))%MOD;
        }
        else{
            for(int i=1;i<=min(limit, one);i++)
            res=(res+helper(zero, one-i, true, limit))%MOD;
        }
        return t[zero][one][wasOne]=res;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t,-1,sizeof(t));
        int startsZero=helper(zero, one ,false, limit);
        int startsOne=helper(zero, one, true, limit);
        return (startsZero+startsOne)%MOD;
    }
};
