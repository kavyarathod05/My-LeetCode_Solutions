class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string temp = "";
        
        for(int i=0;i<n;i++){
            if(temp.size()==0 || temp.back()< num[i]){
                temp.push_back(num[i]);
            }    
            else{

                while(!temp.empty() && temp.back() > num[i] && k>0){
                    k--;
                    temp.pop_back();
                }
                temp.push_back(num[i]);
            }
        }
        while(k>0){
            temp.pop_back();
            k--;
        }
        string st = "";
        int i=0;
        while(i<temp.size() && temp[i]=='0') i++;
        st = temp.substr(i);
        return st == "" ? "0" : st;
    }
};