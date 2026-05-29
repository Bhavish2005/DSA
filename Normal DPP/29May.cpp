class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int currsum=0;
            int currnum=nums[i];
            while(currnum){
                int val=currnum%10;
                currsum+=val;
                currnum/=10;
            }
            mini=min(mini, currsum);
        }
        return mini;
    }
};
