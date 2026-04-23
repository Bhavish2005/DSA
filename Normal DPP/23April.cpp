class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        vector<long long> prefix(n,0);
        vector<long long>suffix(n,0);
        unordered_map<int,long long>mp;
        unordered_map<int,long long>freq;
        vector<long long >freqleft(n,0);
        vector<long long>freqright(n,0);
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end()){
                prefix[i]=mp[nums[i]];
                freqleft[i]+=freq[nums[i]];
                
            }
            mp[nums[i]]+=i;
            freq[nums[i]]++;
        }
        mp.clear();
        freq.clear();
        for(int i=n-1;i>=0;i--){
            if(mp.find(nums[i])!=mp.end()){
                suffix[i]=mp[nums[i]];
                freqright[i]+=freq[nums[i]];
               
            }
             mp[nums[i]]+=i;
             freq[nums[i]]++;
        }
        vector<long long>ans;
        for(int i=0;i<n;i++){
            long long left=freqleft[i]*i-prefix[i];
            long long right=suffix[i]-freqright[i]*i;
            ans.push_back(left+right);
        }
        return ans;

    }
};
