class Solution {
public: 
    int revs(int num){
        int res=0;
        while(num>0){
            int helper=num%10;
            res=res*10+helper;
            num/=10;
        }
        return res;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int min_ans=INT_MAX;
        unordered_map<int, int >mp;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
             int number=revs(nums[i]);
            if(mp.find(number)!=mp.end())
            {
                min_ans=min(abs(mp[number]-i), min_ans);
            }
            mp[nums[i]]=i;
        }
        return min_ans==INT_MAX?-1:min_ans;
    }
};
