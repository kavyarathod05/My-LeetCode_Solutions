#define mod 1000000007
class Solution {
public:
    long long powers(long long x, long long n){
        long long ans =1;
        while(n>0){
            if(n%2==1){
                ans *= x;
                ans%=mod;
            }
            
                x*=x;
                x%=mod;
                n/=2;
            

        }
        return ans%mod;
    }
    int countGoodNumbers(long long n) {
        long long odd=n/2;
        long long even= n/2 + n%2;
        long long total= (powers(5,even)*powers(4,odd)) %mod;
        return total;
    }
};