class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.size();
        while(1){
            int index= s.find(part);
            if(index != string::npos){
                s.erase(index, part.size());
            }
            else{
                break;
            }
        }
        return s;
    }
};