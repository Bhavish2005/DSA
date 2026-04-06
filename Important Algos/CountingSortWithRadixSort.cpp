    int n;
    void countingSort(vector<int>&nums, int exp){
        vector<int>output(n);
        vector<int>helper(10,0);
         for(int i=0;i<n;i++){
            helper[(nums[i]/exp)%10]++;
         }
         for(int i=1;i<10;i++){
            helper[i]+=helper[i-1];
         }
         for(int i=n-1;i>=0;i--){
            output[helper[(nums[i]/exp)%10]-1]=nums[i];
            helper[(nums[i]/exp)%10]--;
         }
         nums=output;
    }
    void radixSort(vector<int>&nums){
        int maxi=*max_element(nums.begin(), nums.end());
        for(long long exp=1;maxi/exp>0;exp*=10){
            countingSort(nums,exp);
        }
    }
