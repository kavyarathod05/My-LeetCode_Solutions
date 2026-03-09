#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9+7;

    int numberOfStableArrays(int zero, int one, int limit) {

        static int dp[201][201][2][201];
        memset(dp,0,sizeof(dp));

        if(zero>0) dp[1][0][0][1] = 1;
        if(one>0) dp[0][1][1][1] = 1;

        for(int i=0;i<=zero;i++){
            for(int j=0;j<=one;j++){
                for(int last=0;last<2;last++){
                    for(int cnt=1;cnt<=limit;cnt++){

                        int cur = dp[i][j][last][cnt];
                        if(cur==0) continue;

                        // place 0
                        if(i+1<=zero){
                            if(last==0){
                                if(cnt+1<=limit)
                                    dp[i+1][j][0][cnt+1] = (dp[i+1][j][0][cnt+1] + cur)%MOD;
                            }
                            else{
                                dp[i+1][j][0][1] = (dp[i+1][j][0][1] + cur)%MOD;
                            }
                        }

                        // place 1
                        if(j+1<=one){
                            if(last==1){
                                if(cnt+1<=limit)
                                    dp[i][j+1][1][cnt+1] = (dp[i][j+1][1][cnt+1] + cur)%MOD;
                            }
                            else{
                                dp[i][j+1][1][1] = (dp[i][j+1][1][1] + cur)%MOD;
                            }
                        }

                    }
                }
            }
        }

        long long ans=0;

        for(int last=0;last<2;last++)
            for(int cnt=1;cnt<=limit;cnt++)
                ans=(ans+dp[zero][one][last][cnt])%MOD;

        return ans;
    }
};