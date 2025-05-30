class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        long i=0;
        long ans=0;
        bool sign = true;
        while(i<n && s[i]==' ')i++;
        if(i<n && (s[i]=='-' || s[i]=='+')){
            sign=(s[i]=='+');
            i++;
        }
        while(i<n && s[i]>='0' && s[i]<='9'){
            ans= ans*10 + (s[i]-'0');
            if (ans > INT_MAX) {
                return sign ? INT_MAX : INT_MIN;
            }
            i++;
        }
        ans= sign?ans: -ans;
        return (int)ans;
    }
};