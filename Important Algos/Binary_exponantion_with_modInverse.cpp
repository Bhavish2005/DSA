long long binaryExpo(long long num , int exp){
        long long res=1;
        num%=mod;
        while(exp>0){
            if(exp%2)//odd power case...
            res=(res*num)%mod;
            num=(num*num)%mod;///even case....
            exp/=2;
        }
        return res;
    }
    long long  modInverse(long long num ){
        return binaryExpo(num , mod-2);
    }
