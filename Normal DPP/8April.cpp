class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int mod=1e9+7;
       for(auto &ind:queries){
        int left=ind[0];
        int right=ind[1];
        int value=ind[3];
        int step=ind[2];
        for(int i=left;i<=right;i+=step){
            nums[i]=((long long )nums[i]*value)%mod;
        }
       }
       int ans=0;
        for(int i=0;i<nums.size();i++){
            ans^=nums[i];
        }
        return ans;
    }
};
