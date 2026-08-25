class Solution {
    public int missingMultiple(int[] nums, int k) {
        int n =nums.length;
        int ans=0;
        Set<Integer>s=new HashSet<>();
        for(int num:nums){
            s.add(num);
        }
         for(int i=0;i<2*n;i++){
            int currMul =k*(i+1);
            if(!s.contains(currMul))
            return currMul;
            ans=currMul;
         }
         return ans;
    }
}	
