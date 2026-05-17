class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<pair<int,int>> q;
        vector<int>visited(arr.size(),false);
 
        if(start+arr[start]<arr.size()){
        int next=start+arr[start];
        q.push({start,next});
    }
        if(start-arr[start]>=0){
        int prev=start-arr[start];
        q.push({start,prev});

    }

    while(!q.empty()){
        int curr=q.front().first;
        int next=q.front().second;
        q.pop();
        visited[curr]=true;
        if(arr[curr]==0)
        return true;
         if(next+arr[next]<arr.size() && !visited[next +arr[next]])
        q.push({next,next+arr[next]});
        if(next-arr[next]>=0 && !visited[next-arr[next]])
        q.push({next,next-arr[next]});

    }
    return false;
    }
};
