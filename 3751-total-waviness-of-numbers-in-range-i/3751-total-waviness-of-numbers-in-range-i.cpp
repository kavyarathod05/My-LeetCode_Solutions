class Solution {
public:
    int check(int i){
        int peak=0;
        int valley =0 ;
        string s= "";
        while(i>0){
            s+= (i%10+ '0');
            i/=10;
        }
        reverse(s.begin(), s.end());
        
        for(int i=1;i<s.size()-1;i++){
            if((s[i]>s[i-1]) && (s[i]>s[i+1])) peak++;
            else if((s[i]<s[i-1]) && (s[i]<s[i+1])) valley++;
        }
        return peak+valley;
    }
    int totalWaviness(int num1, int num2) {
        int cnt=0;
        if(num2<=99) return 0;
        if(num1<=99){
            num1=100;
        }        
        for(int i=num1;i<=num2;i++){
            cnt+=check(i);
        }
        return cnt;
    }
};