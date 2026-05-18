class Solution {
public:
    int minJumps(vector<int>& nums) {
        if(nums.size()<=1)
        return 0;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        vector<bool>visited(nums.size(),false);
        queue<int>q;
        q.push(0);
        visited[0]=true;
        int ans =0;
        while(!q.empty()){
            int sz=q.size();
             for(int i=0;i<sz;i++){
                    int curr=q.front();
                    int val=nums[curr];
                    q.pop();
                    if(curr==nums.size()-1)
                    return ans;
                
            int right=curr+1;
            int left=curr-1;
            if(right<nums.size() && !visited[right]){
                visited[right]=true;
                q.push(right);
            }
            if(left>=0 && !visited[left]){
                visited[left]=true;
                q.push(left);
            }
            for(int nextJump:mp[val]){
                if(!visited[nextJump]){
                    visited[nextJump]=true;
                    q.push(nextJump);
                }
            }
            mp.erase(val);
        }
        ans++;
        }
        return -1;
        
    }
};
