class Solution {
    public boolean sumGame(String num) {
        Integer sumDiff=0;
        Integer Qdiff=0;
        Integer n=num.length();
        for(int i=0;i<n/2;i++){
            if( num.charAt(i)=='?')Qdiff++;
            else sumDiff+=(num.charAt(i)-'0');
        }
        for(int i=n/2;i<n;i++){
            if(num.charAt(i)=='?') Qdiff--;
            else sumDiff-=(num.charAt(i)-'0');
        }
        if(Qdiff%2!=0)
        return true;
        return (sumDiff + (Qdiff/2)*9)!=0;
    }
}
