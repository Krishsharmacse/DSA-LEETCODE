class Solution {
    int MOD=1e9+7;
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r-l+1;
        vector<int>dp(m,1);
        bool reverse=true;
        for(int len=2;len<=n;++len){
            int sum=0;
            if(reverse){
                for(int i=m-1;i>=0;--i){
                    int val=dp[i];
                    dp[i]=sum;
                    sum=(sum+val)%MOD;
                }

            }
            else{
                for(int i =0;i<m;++i){
                    int val=dp[i];
                    dp[i]=sum;
                    sum=(sum+val)%MOD;

                }
            }
            reverse=!reverse;
        }
        return ((accumulate(dp.begin(),dp.end(),0LL)%MOD)<<1)%MOD;
        
    }
};