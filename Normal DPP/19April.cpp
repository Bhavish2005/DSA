class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i=nums1.size()-1;
        int j=nums2.size()-1;
        int ans=0;
        while(i>=0 && j>=0)
        {
            if(nums1[i]<=nums2[j]){
                ans=max(ans, j-i);
                i--;
            }
            else{
                if(i<j)
                         j--;
                
                else
                {
                    j--;
                    i--;
                }
           
            }
        }
        return ans ;
    }
};
