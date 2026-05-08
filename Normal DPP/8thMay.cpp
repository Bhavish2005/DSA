class Solution {
public:
    vector<bool>getPrimes(int n){
        vector<bool>primes(n+1,true);
        primes[0]=false;
        if(n>=1)
        primes[1]=false;
        for(int i=2;i*i<=n;i++){
            if(primes[i]){
                for(int j=i*i;j<=n;j+=i)
                primes[j]=false;
            }
        }
        return primes;
    }
    int minJumps(vector<int>& nums) {
        int n=nums.size();
        int max_val=*max_element(nums.begin(), nums.end());
        vector<bool>primes=getPrimes(max_val);
        unordered_map<int,vector<int>>mp;
        vector<bool>visited(n,false);
        queue<int>q;
        q.push(0);
        visited[0]=true;
        int jumps=0;
        for(int i=0;i<n;i++){
            int curr=nums[i];
            for(int p=2;p*p<=curr;p++){
                if(curr%p==0){
                    if(primes[p])
                    mp[p].push_back(i);
                    while(curr%p==0)
                    curr/=p;
                }
            }
            if (curr > 1 && primes[curr]) {
                mp[curr].push_back(i);
            }
        }
        while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            int curr=q.front();
            q.pop();
            if(curr==n-1)
            return jumps;

            if(curr+1<n && !visited[curr+1])
            {
                q.push(curr+1);
                visited[curr+1]=true;
            }
            if(curr-1>=0 && !visited[curr-1]){
                q.push(curr-1);
                visited[curr-1]=true;
            }
            int p=nums[curr];
            if(primes[p] && mp.find(p)!=mp.end()){
                for(auto next_ind:mp[p]){
                    if(!visited[next_ind]){
                    visited[next_ind]=true;
                    q.push(next_ind);
                }
            }
            mp.erase(p);
        }
        }
        jumps++;
    }
    return -1;
    }
};
