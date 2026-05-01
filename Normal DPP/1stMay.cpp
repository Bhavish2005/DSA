class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
    vector<int>helper(nums.size(),0);
    int n=nums.size();
    for(int i=0;i<n;i++){
        helper[0]+=(nums[i])*i;
    }
    int sumi=accumulate(nums.begin(), nums.end(),0);
        int maxi=helper[0];
        for(int i=1;i<n;i++){
            helper[i]=helper[i-1]+sumi-nums[n-i]*n;
            maxi=max(maxi, helper[i]);
        }
        return maxi;
    }
};
