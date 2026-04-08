class Solution {
public:
    long long dp[20][2][2][201][2];
    // index , tight , started, diff, parity

    long long solve(string s, int ind, int tight, int started, int diff, int parity){
        if(ind== s.size()){
            return (started && diff==0);
        }
        // step -1 check recomputed or not
        if(dp[ind][tight][started][diff+100][parity] != -1) return dp[ind][tight][started][diff+100][parity];
        // step-2: find range for indexes accoring to tight
        int limit = tight ? (s[ind]-'0'): 9;
        long long ans = 0;
        for(int d =0 ; d <= limit ; d++){
            bool newTight = tight && (d==limit);
            bool newStarted = started || (d!=0);
            int newDiff = diff;
            int newParity = parity;
            // if non zero series already started then this case
            if(newStarted){
                if(!started){
                    // first non zero so parity is odd
                    newParity = 0;
                }
                if(newParity == 0){
                    newDiff += d;
                }
                else{
                    newDiff-=d;
                }
                newParity ^= 1;
            }
            ans += solve(s, ind+1, newTight , newStarted, newDiff, newParity);
        }
        return dp[ind][tight][started][diff+100][parity] = ans;
    }
    long long count(long long x){
        string s = to_string(x);
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 1, 0, 0, 0);
    }
    long long countBalanced(long long low, long long high) {
        return count(high)- count(low-1);
    }
};