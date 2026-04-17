class Solution {
public:
    int closestTarget(vector<string>& words, string target, int start) {
        unordered_map<string , vector<int>>mp;
        int n=words.size();
        for(int i=0;i<n;i++){
            mp[words[i]].push_back(i);
        }
        
        int ans=INT_MAX;
        if(mp.find(target)!=mp.end()){
            for(int i=0;i<mp[target].size();i++){
                int curr= min(abs(mp[target][i]-start)%n,(n-abs(mp[target][i]-start))%n);
                ans=min(curr, ans);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};
