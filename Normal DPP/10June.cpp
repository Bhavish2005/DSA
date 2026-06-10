class Solution {
public:
using ll=long long ;
    pair<ll ,ll> count_and_sum_less(ll X, const vector<int>&nums){
        int n=nums.size();
        int L=0;
        ll max_sum =0;
        ll min_sum=0;
         deque<int> max_dq, min_dq;
         ll cnt_less=0, sum_less=0;
         for(int r=0;r<n;r++){
            while(!max_dq.empty() && nums[max_dq.back()]<=nums[r]){
                int i=max_dq.back();
                max_dq.pop_back();
                int prev=max_dq.empty() ? L-1:max_dq.back();
                max_sum-=1LL*nums[i]*(i-prev);
            }
            int prev_max=max_dq.empty()?L-1:max_dq.back();
            max_sum+=1LL*nums[r]*(r-prev_max);
            max_dq.push_back(r);

            while (!min_dq.empty() && nums[min_dq.back()] >= nums[r]) {
                int idx = min_dq.back();
                min_dq.pop_back();
                int prev = min_dq.empty() ? L - 1 : min_dq.back();
                min_sum -= 1LL * nums[idx] * (idx - prev);
            }
            int prev_min = min_dq.empty() ? L - 1 : min_dq.back();
            min_sum += 1LL * nums[r] * (r - prev_min);
            min_dq.push_back(r);
            while(L<=r && nums[max_dq.front()]-nums[min_dq.front()]>=X){
                max_sum-=nums[max_dq.front()];
                if(L==max_dq.front())
                max_dq.pop_front();
                min_sum-=nums[min_dq.front()];
                if(L== min_dq.front())
                min_dq.pop_front();
                L++;
            }
            cnt_less+=(r-L+1);
            sum_less+=(max_sum-min_sum);

         }
         return {cnt_less, sum_less};
    }
    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();
        ll total_subarrays=1LL*n*(n+1)/2;
        pair<ll, ll>total=count_and_sum_less(2000000000LL, nums);
        ll total_sum=total.second;
        ll low=0;
        ll high=1000000000LL;
        ll v_star=0;
        while(low<=high){
            ll mid=low+(high-low)/2;
            pair<ll, ll> ans=count_and_sum_less(mid, nums);
            ll cnt_ge=total_subarrays-ans.first;
            if(cnt_ge>=k){
                v_star=mid;
                low=mid+1;
            }
            else
            high=mid-1;
        }
        pair<ll, ll> ans_v1=count_and_sum_less(v_star+1, nums);
        ll cnt_ge_v1=total_subarrays-ans_v1.first;
        ll sum_ge_v1=total_sum-ans_v1.second;
        return sum_ge_v1+(k-cnt_ge_v1)*v_star;
         
    }
};
