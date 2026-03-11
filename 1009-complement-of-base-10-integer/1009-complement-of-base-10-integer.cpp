class Solution {
public:
    int bitwiseComplement(int n) {

        if(n == 0) return 1;

        string s = "";

        while(n > 0){
            int bit = n % 2;
            s += (bit + '0');
            n /= 2;
        }

        reverse(s.begin(), s.end());

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0') s[i] = '1';
            else s[i] = '0';
        }

        int ans = 0;
        int p = 0;

        for(int i = s.size()-1; i >= 0; i--){
            ans += (s[i]-'0') * pow(2, p);
            p++;
        }

        return ans;
    }
};