class Solution {
public:
    bool check(vector<int>& nums) { 
        int count=0;
        int n=nums.size();
        if(nums[n-1]>nums[0])
         count++;
         for(int i=1;i<n;i++){
            if(count>1)
            return false;
            if(nums[i]<nums[i-1])
            count++;
         }
         
         return count<=1;
    }
};
