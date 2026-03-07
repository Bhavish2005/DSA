class Solution {
public:
    int minFlips(string s) {
	int ans=INT_MAX;
	int i=0;
	int n=s.size();
	int j=0;
	int flip1=0;
	int flip2=0;
	while(j<2*n){
		char expecS1=(j%2 ?'0' :'1');
		char expecS2=(j%2? '1':'0');
		if(s[j%n]!=expecS1)
			flip1++;
		if(s[j%n]!=expecS2)
			flip2++;
		if(j-i+1>n){
			 expecS1=(i%2 ?'0':'1');
			 expecS2=(i%2?'1':'0');
			if(s[i%n]!=expecS1)
				flip1--;
			if( s[i%n]!=expecS2)
				flip2--;
			i++;
		}
		if(j-i+1==n)
		{
			ans=min(ans, min(flip1,flip2));
		}
		j++;
	}
	return ans;
    }
};
