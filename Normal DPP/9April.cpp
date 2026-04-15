class Solution {
public:
   const int mod=1e9+7;
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
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
 
        int n=nums.size();
        int B=sqrt(n);
        vector<vector<int>> diff(B+1,vector<int>(n+B+1,1));
        for(auto&ind:queries){
            int start=ind[0];
            int end=ind[1];
            int step=ind[2];
            int value=ind[3];
            if(step>B){
                for(int i=start;i<=end;i+=step){
                    nums[i]=((long long)nums[i]*value)%mod;
                }
            }
            else{
                int lastindex=start+((end-start)/step)*step;
                diff[step][start]=((long long)diff[step][start]*value)%mod;
                diff[step][lastindex+step]=((long long )diff[step][lastindex+step]*modInverse(value))%mod;
               
            }
        }
         for(int i=1;i<=B;i++){
                    for(int j=0;j<n;j++){
                        if(j>=i)
                        diff[i][j]=((long long)diff[i][j]*diff[i][j-i])%mod;
                        nums[j]=((long long )diff[i][j]*nums[j])%mod;
                    }
                }
                int ans=0;
                for(int i=0;i<n;i++)
                ans^=nums[i];
                return ans;
    }
};
