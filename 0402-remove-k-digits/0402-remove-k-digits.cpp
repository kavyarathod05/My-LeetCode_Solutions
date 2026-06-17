class Solution {
public:
    string removeKdigits(string num, int k) {
        string temp = "";

        for(char c : num){
            while(!temp.empty() && temp.back() > c && k > 0){
                temp.pop_back();
                k--;
            }
            temp.push_back(c);
        }

        while(k > 0 && !temp.empty()){
            temp.pop_back();
            k--;
        }

        int i = 0;
        while(i < temp.size() && temp[i] == '0') i++;

        temp = temp.substr(i);

        return temp.empty() ? "0" : temp;
    }
};