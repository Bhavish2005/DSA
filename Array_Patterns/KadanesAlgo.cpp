class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN;
        int sum=0;
        int n = nums.size();
         for(int i=0;i<n;i++){
            sum+=nums[i];
            maxSum=max(sum , maxSum);
            if(sum<0)
            sum=0;
           
         }
         return maxSum;
    }
};
