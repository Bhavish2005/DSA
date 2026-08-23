class Solution {
    private Integer[] anscheck(int n){
        Integer sum =0, prod=1;
        while(n>0){
            Integer j=n%10;
            sum+=j;
            prod*=j;
            n/=10;
        }
        return new Integer []{sum ,prod};
    }
    public boolean checkDivisibility(int n) {
        Integer[] ans=anscheck(n);
        return n%(ans[0]+ans[1])==0;
    }
}
